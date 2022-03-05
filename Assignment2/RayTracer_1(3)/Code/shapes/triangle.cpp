#include "triangle.h"

Hit Triangle::intersect(Ray const &ray)
{
    // float D = -(N.x * v0.x + N.y * v0.y + N.z * v0.z);
    // float t = -((N.x * ray.O.x + N.y * ray.O.y + N.z * ray.O.z + ray.D) 
    //             / (N.x * ray.R.x + N.y * ray.R.y + N.z * ray.O.z));

    return Hit::NO_HIT(); // placeholder
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
    N = (v1 - v0).cross(v1 - v2);
    N.normalize();
}
