#include "mesh.h"

#include "../objloader.h"
#include "../vertex.h"
#include "triangle.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

Hit Mesh::intersect(Ray const &ray)
{
    ObjectPtr t;
    bool isHit;
    Hit minimal_Hit(numeric_limits<double>::infinity(), Triple());
    Hit maximal_Hit(numeric_limits<double>::infinity(), Triple());
    
    // For-loop to iterate over the triagles from the mesh and 
    //check if there is an intersection
    for(size_t j = 0; j < d_tris.size(); j++) {
        t = d_tris[j];
        Hit hitIntersection = t->intersect(ray);

        if(minimal_Hit.t > hitIntersection.t) {
            isHit = true;
            if(maximal_Hit.t > hitIntersection.t) {
                maximal_Hit.t = hitIntersection.t;
                maximal_Hit.N = hitIntersection.N;
            }
        }
    }

    // In case there is a hit return
    if(isHit) {
        return maximal_Hit;
    } else {
        return Hit::NO_HIT();
    }
}

Triple Mesh::meshRot(Triple toRotate, Triple rotation) {
    Triple tmpVector = toRotate;

    // X-axis
    tmpVector.x = toRotate.x;
    tmpVector.y = cos(rotation.x) * toRotate.y - sin(rotation.x) * toRotate.z;
    tmpVector.z = cos(rotation.x) * toRotate.z + sin(rotation.x) * toRotate.y;

    // Save the modifications
    toRotate = tmpVector;

    // Y-axis
    tmpVector.x = cos(rotation.y) * toRotate.x + sin(rotation.y) * toRotate.z;
    tmpVector.y = toRotate.y;
    tmpVector.z = cos(rotation.y) * toRotate.z + sin(rotation.y) * (-toRotate.x);

    // Save the modifications
    toRotate = tmpVector;

    // Z-axis
    tmpVector.x = cos(rotation.z) * toRotate.x - sin(rotation.z) * toRotate.y;
    tmpVector.y = cos(rotation.z) * toRotate.y + sin(rotation.z) * toRotate.x;
    tmpVector.z = toRotate.z;

    return tmpVector;
}

Mesh::Mesh(string const &filename, Point const &position, Vector const &rotation, Vector const &scale)
{
    OBJLoader model(filename);
    d_tris.reserve(model.numTriangles());
    vector<Vertex> vertices = model.vertex_data();
    for (size_t tri = 0; tri != model.numTriangles(); ++tri)
    {
        Vertex one = vertices[tri * 3];
        Point v0(one.x, one.y, one.z);

        Vertex two = vertices[tri * 3 + 1];
        Point v1(two.x, two.y, two.z);

        Vertex three = vertices[tri * 3 + 2];
        Point v2(three.x, three.y, three.z);

        // Functionality for non-uniform scaling, rotation and translation to the three points
        // of the triangle (v0, v1, and v2).

        // Non-uniform scaling
        v0 = v0 * scale;
        v1 = v1 * scale;
        v2 = v2 * scale;

        // Rotation
        v0 = meshRot(v0, rotation);
        v1 = meshRot(v1, rotation);
        v2 = meshRot(v2, rotation);

        // Translation
        v0 = v0 + position;
        v1 = v1 + position;
        v2 = v2 + position;

        d_tris.push_back(ObjectPtr(new Triangle(v0, v1, v2)));
    }

    cout << "Loaded model: " << filename << " with " <<
        model.numTriangles() << " triangles.\n";
}
