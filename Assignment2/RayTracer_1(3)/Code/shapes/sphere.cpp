#include "sphere.h"

#include <cmath>

using namespace std;

Hit Sphere::intersect(Ray const &ray)
{
    /****************************************************
    * RT1.1: INTERSECTION CALCULATION
    *
    * Given: ray, position, r
    * Sought: intersects? if true: *t
    *
    * Insert calculation of ray/sphere intersection here.
    *
    * You have the sphere's center (position) and radius (r) as well as
    * the ray's origin (ray.O) and direction (ray.D).
    *
    * If the ray does not intersect the sphere, return false.
    * Otherwise, return true and place the distance of the
    * intersection point from the ray origin in *t (see example).
    ****************************************************/

    // Placeholder for actual intersection calculation.
    // Vector originToPosition = (position - ray.O).normalized();
    // if (originToPosition.dot(ray.D) < 0.999)
    //     return Hit::NO_HIT();

    // double t = 1000;


    /**************** OUR CODE *************************/
    Vector N;
    N.x = 0;
    N.y = 0;
    N.z = 0;

    double A = (ray.D).dot(ray.D); // d*d
    double B = (ray.D).dot(ray.O-position); // 2d * (e - c)
    double C = (ray.O-position).dot(ray.O-position) - (r*r); // (e - c) * (e - c) - R*R

    double D = sqrt((B*B) - (A*C));
    double t;

    if (D < 0) {
        return Hit::NO_HIT();
    } if (D == 0) { // there is only one point in which the ray intersect the sphere
        t = -B/A;
        return Hit(t, N);
    } else { // there are two points and the smallest t is the one closest to the eye/camera
        double t1 = (-B + D)/A;
        double t2 = (-B - D)/A;
        t = (t1 < t2 ? t1 : t2);
        return Hit(t, N);
    }

    /****************************************************
    * RT1.2: NORMAL CALCULATION
    *
    * Given: t, position, r
    * Sought: N
    *
    * Insert calculation of the sphere's normal at the intersection point.
    ****************************************************/

    //  Vector N /* = ... */; //use LATER

    return Hit(t, N);
}

Sphere::Sphere(Point const &pos, double radius)
:
    position(pos),
    r(radius)
{}
