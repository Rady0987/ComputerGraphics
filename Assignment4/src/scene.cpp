#include "scene.h"

#include "hit.h"
#include "image.h"
#include "material.h"
#include "ray.h"

#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

pair<ObjectPtr, Hit> Scene::castRay(Ray const &ray) const
{
    // Find hit object and distance
    Hit min_hit(numeric_limits<double>::infinity(), Vector());
    ObjectPtr obj = nullptr;
    for (unsigned idx = 0; idx != objects.size(); ++idx)
    {
        Hit hit(objects[idx]->intersect(ray));
        if (hit.t < min_hit.t)
        {
            min_hit = hit;
            obj = objects[idx];
        }
    }

    return pair<ObjectPtr, Hit>(obj, min_hit);
}

Color Scene::trace(Ray const &ray, unsigned depth, bool inside)
{
    pair<ObjectPtr, Hit> mainhit = castRay(ray);
    ObjectPtr obj = mainhit.first;
    Hit min_hit = mainhit.second;

    // No hit? Return background color.
    if (!obj)
        return Color(0.0, 0.0, 0.0);

    Material const &material = obj->material;
    Point hit = ray.at(min_hit.t);
    Vector V = -ray.D;

    // Pre-condition: For closed objects, N points outwards.
    Vector N = min_hit.N;

    // The shading normal always points in the direction of the view,
    // as required by the Phong illumination model.
    Vector shadingN;
    if (N.dot(V) >= 0.0)
        shadingN = N;
    else
        shadingN = -N;

    Color matColor = material.color;

    // Add ambient once, regardless of the number of lights.
    Color color = material.ka * matColor;

    // Add diffuse and specular components.
    for (auto const &light : lights)
    {   
        int shadow = 1;
        if (renderShadows == true) {
            // cast a shadow ray and check whethet it hit an object
            Ray shadowRay = Ray(hit + shadingN * epsilon, (light->position - hit)); // create the shadow ray
            pair<ObjectPtr, Hit> shadowRayHit = castRay(shadowRay); // run the ray and get feedback on object hit
            Point shadowHit = shadowRay.at(shadowRayHit.second.t); // capture the point of ray hit
            Vector shadowToObj = shadowHit - hit; // create the vector from shadow to the object 
            Vector shadowToLight = light->position - hit; // create the vector from the shadow to the light
            if (shadowToObj.length() > shadowToLight.length()) { // if the light is closer than the object, it has no shadow
                shadowRayHit.first = nullptr; // dont draw shadow from the distant objectS
            }           
            shadow = (shadowRayHit.first == nullptr ? 1 : 0); // dont add light in the shadow area
        }
        Vector L = (light->position - hit).normalized();

        // Add diffuse.
        double dotNormal = shadingN.dot(L);
        double diffuse = std::max(dotNormal, 0.0);
        color += shadow * diffuse * material.kd * light->color * matColor;

        // Add specular.
        if(dotNormal > 0)
        {
            Vector reflectDir = reflect(-L, shadingN); // Note: reflect(..) is not given in the framework.
            double specAngle = std::max(reflectDir.dot(V), 0.0);
            double specular = std::pow(specAngle, material.n);

            color += shadow * specular * material.ks * light->color;
        }
    }

    if (depth > 0 and material.isTransparent)
    {
        // The object is transparent, and thus refracts and reflects light.
        // Use Schlick's approximation to determine the ratio between the two.
        double nt, ni, kr0, kr, kt;
        Triple t(0, 0, 0);

        Ray reflection(hit + epsilon * shadingN, reflect(ray.D, shadingN));

        // Check if the ray is inside the object or not, to assign the refractive index
        if(inside) {
            ni = material.nt;
            nt = 1.0;
        
        } else {
            ni = 1.0;
            nt = material.nt;
        }

        // Calculations needed for Schlick's approximation
        kr0 = pow((ni - nt)/(ni + nt), 2);
        kr = kr0 + (1.0 - kr0) * pow((1.0 - ((-ray.D).dot(shadingN))), 5);
        kt = 1.0 - kr;

        // Implementation of Snell's Law
        double phiAngle = 1.0 - (ni * ni * (1.0 - pow((ray.D).dot(shadingN), 2)) / (nt * nt));
        t = (ni * (ray.D - (ray.D).dot(shadingN) * shadingN) / nt) - shadingN * sqrt(phiAngle);

        Ray refraction(hit - epsilon * shadingN, t.normalized());
    	color += trace(reflection, depth - 1, inside) * kr + trace(refraction, depth - 1, not inside) * kt;

    }
    else if (depth > 0 and material.ks > 0.0) // 3.2
    {
        // The object is not transparent, but opaque.
        Vector reflectDir = reflect(-V, shadingN); // create new reflection direction
        Ray bouncedRay = Ray(hit + shadingN * epsilon, reflectDir); // make a ray out of that
        color += trace(bouncedRay, depth - 1, inside) * material.ks; // trace the ray
    }

    return color;
}

void Scene::render(Image &img)
{
    unsigned w = img.width();
    unsigned h = img.height();

    for (unsigned y = 0; y < h; ++y)
        for (unsigned x = 0; x < w; ++x)
        {
            Point pixel(x + 0.5, h - 1 - y + 0.5, 0);
            Ray ray(eye, (pixel - eye).normalized());
            Color col = trace(ray, recursionDepth, false);
            col.clamp();
            img(x, y) = col;
        }
}

// --- Misc functions ----------------------------------------------------------

// Defaults
Scene::Scene()
:
    objects(),
    lights(),
    eye(),
    renderShadows(false),
    recursionDepth(0),
    supersamplingFactor(1)
{}

void Scene::addObject(ObjectPtr obj)
{
    objects.push_back(obj);
}

void Scene::addLight(Light const &light)
{
    lights.push_back(LightPtr(new Light(light)));
}

void Scene::setEye(Triple const &position)
{
    eye = position;
}

unsigned Scene::getNumObject()
{
    return objects.size();
}

unsigned Scene::getNumLights()
{
    return lights.size();
}

void Scene::setRenderShadows(bool shadows)
{
    renderShadows = shadows;
}

void Scene::setRecursionDepth(unsigned depth)
{
    recursionDepth = depth;
}

void Scene::setSuperSample(unsigned factor)
{
    supersamplingFactor = factor;
}
