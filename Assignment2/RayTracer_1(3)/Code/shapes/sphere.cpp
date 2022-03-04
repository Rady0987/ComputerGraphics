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
    // N.x = 0;
    // N.y = 0;
    // N.z = 0;

    double A = (ray.D).dot(ray.D); // d*d
    double B = (ray.D).dot(ray.O-position); // 2d * (e - c)
    double C = (ray.O-position).dot(ray.O-position) - (r*r); // (e - c) * (e - c) - R*R

    double D = sqrt((B*B) - (A*C));
    double t;

    if (D < 0) { // test how many intersections there are by checking discriminant
        return Hit::NO_HIT();
    } if (D == 0) { // there is only one point in which the ray intersect the sphere
        t = -B/A;
    } else { // there are two points and the smallest t is the one closest to the eye/camera
        double t1 = (-B + D)/A; // compute both values for t with the quadratic formulas
        double t2 = (-B - D)/A;
        if (min(t1,t2) > 0) { // if both intersections are in front of the camera then use the closest one
            t = min(t1,t2);
        } else { // if the camera is in the sphere then use the one in front of the camera 
            t = max(t1,t2);
        }
    }

    /****************************************************
    * RT1.2: NORMAL CALCULATION
    *
    * Given: t, position, r
    * Sought: N
    *
    * Insert calculation of the sphere's normal at the intersection point.
    ****************************************************/

    N = ((ray.at(t))-position).normalized(); // normal vector is created by substracting
                                            //  the centre of the sphere from the ray intersection point
    Vector V = -ray.D; // create the view vector

    if (V.dot(N) >= 0) { // check wether the N vector is pointing in the right direction
        return (t > 0 ? Hit(t, N) : Hit::NO_HIT());
    } else {
        N = -N; // flip N if the ray is coming from inside the sphere
        return (t > 0 ? Hit(t, N) : Hit::NO_HIT());
    }
    
}

Sphere::Sphere(Point const &pos, double radius)
:
    position(pos),
    r(radius)
{}
