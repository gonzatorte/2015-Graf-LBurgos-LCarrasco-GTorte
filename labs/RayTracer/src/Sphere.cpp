#include "Sphere.h"

Sphere::Sphere()
{
    //ctor
}

<<<<<<< HEAD
=======
void Sphere::read(tinyxml2::XMLElement* element) {

    radius = atof(element->Attribute("radius"));
    center = Vector(atof(element->Attribute("centerX")), atof(element->Attribute("centerY")), atof(element->Attribute("centerZ"));
    super.read(element);
}

>>>>>>> 3ef7e8a17efc01e56f2676bac37f809a3a56110c
Sphere::~Sphere()
{
    //dtor
}
