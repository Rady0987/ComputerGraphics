#include "triangle.h"
#include <tgmath.h>

/* The source basic concepts and general algorithm:
 https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/ray-triangle-intersection-geometric-solution
 */

Hit Triangle::intersect(Ray const &ray)
{
    double Eps = 0.0000001;

    if(N.dot(ray.D) > 0) 
        N = -N;
   
    Triple v0v1Edge = v1 - v0;
    Triple v0v2Edge = v2 - v0;

    Triple vectorP = ray.D.cross(v0v2Edge);
    double determinant = v0v1Edge.dot(vectorP);

    /* Check the case when the plane that contains the 
    triangle is parallel to the ray (ray direction) */
    if(fabs(determinant) < Eps)
        return Hit::NO_HIT();
    
    double determinantInverse = 1.0 / determinant;
    
    // Calculate the vector from ray origin to P (the hit point on the plane)
    Triple vectorT = ray.O - v0;

    // Normalizing u for cases when determinant is negative
    double u = vectorT.dot(vectorP) * determinantInverse;

    // Check for the case when triangle is behind the ray
    if(u < 0 || u > 1)
        return Hit::NO_HIT();
    
    Triple vectorQ = vectorT.cross(v0v1Edge);
    double v = ray.D.dot(vectorQ) * determinantInverse;

    // Check if the ray intersects the triangle
    if(v + u > 1 || v < 0)
        return Hit::NO_HIT();
    
    // Calculate the distance as we know that the triangle is intersected
    double t = v0v2Edge.dot(vectorQ) * determinantInverse;

    if(t > Eps) {
        return Hit(t, N);
    } else {
        return Hit::NO_HIT();
    }
}

Triangle::Triangle(Point const &v0,
                   Point const &v1,
                   Point const &v2)
:
    v0(v0),
    v1(v1),
    v2(v2),
    N()
{
    // Calculate the surface normal here and store it in the N,
    // which is declared in the header. It can then be used in the intersect function.
    N = (v1 - v0).cross(v2 - v0); 
    N.normalize();
}
