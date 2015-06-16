#include "Shade.h"

Shade::Shade()
{
    //ctor
}

Shade::~Shade()
{
    //dtor
}

bool shadow(Ray & ray, Figure * fig){
    Scene* s = Scene::getInstance();
    bool interfiere = true;
    Isect isect = fig->intersect(ray);
    double minDistance = isect.hited ? isect.distance : 5000000;
    list<Figure*>::iterator it;
    for (it=s->figures.begin(); it!=s->figures.end(); ++it){
        Figure* F = *it;
        isect = F->intersect(ray);
        if (isect.hited)
        {
            if (isect.distance < minDistance)
            {
                if (isect.distance < minDistance)
                {
                    interfiere = false;
                    break;
                }
            }
        }
    }
    return interfiere;

}

Vector specularDirection(Vector incidentRay, Vector normal){
    return (incidentRay + normal * (incidentRay * normal * -2)).UnitVector();
}

Vector Shade::shadeRay(Ray &ray, Isect & isect, int level, int weight){
    Scene* s = Scene::getInstance();
    Figure* figure = isect.figure;
    Vector normal = isect.normal;
    Vector point = isect.surfacePoint;
    Trace trace;
    Vector color;
    Vector colorReflexion;
    color.x = figure->color.x;
    color.y = figure->color.y;
    color.z = figure->color.z;

    if (ray.direction.dotProduct(normal)>0){
        normal = normal*-1;
    }

    Vector specular_vector = specularDirection(ray.direction, normal);

    list<Light*>::iterator it;
    for (it=s->lights.begin(); it!=s->lights.end(); ++it)
    {
        Light * curr_light = (*it);
        Vector lightDir = (curr_light->position - point);
        Ray rayL = Ray(curr_light->position, point - curr_light->position);
        float difuse_angle = lightDir.UnitVector() * normal;
        if((difuse_angle > 0) && shadow(rayL, figure))
        {
            color = color + (curr_light->ambient_intesity * figure->kamb);
            color = color + (curr_light->difuse_intesity * (figure->kdif * difuse_angle));
//            color = color +
//                    (curr_light->spec_intesity * figure->kspec *
//                             powf((ray.origin*(-1)) * specular_vector, figure->shininess));
        }
    }

    int maxLevel = 3;
    int minWeight = 0.1;
    if (level + 1 < maxLevel){
        // Reflexion
        if (weight * figure->kspec > minWeight && figure->reflexion){
            Ray rayStart;
            rayStart.direction = specular_vector;
            rayStart.origin = rayStart.direction*0.1 + point;
            colorReflexion = trace.traceRay(rayStart, level + 1, weight * figure->kspec);
            color = color + colorReflexion * figure->kspec;
        }
    }

    color.x = color.x < 256 ? color.x : 255;
    color.y = color.y < 256 ? color.y : 255;
    color.z = color.z < 256 ? color.z : 255;

    return color;
}
