#include "quad.h"

#include <limits>

using namespace std;

Hit Quad::intersect(Ray const &ray)
{
    Hit minimal_Hit(numeric_limits<double>::infinity(), Triple());
    Hit intersectionT1 = T1->intersect(ray);
    Hit intersectionT2 = T2->intersect(ray);

    // Check which of the quad triangles is closer to 
    //the ray and return it
    if(intersectionT1.t < minimal_Hit.t)
        return intersectionT1;
    
    if(intersectionT2.t < minimal_Hit.t)
        return intersectionT2;

    return Hit::NO_HIT();
}

Quad::Quad(Point const &v0,
           Point const &v1,
           Point const &v2,
           Point const &v3)
{
    // Store and/or process the points defining the quad here.
    T1 = new Triangle(v0, v2, v3);
    T2 = new Triangle(v0, v1, v2);
}
