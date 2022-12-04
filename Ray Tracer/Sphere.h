#pragma once

#include "Ray.h"

struct Sphere {
    Vector center;
    double radius;
    Sphere(const Vector& center, double radius);

    Vector getNormal(const Vector& pi) const;

    bool intersect(const Ray& ray, double& t) const;
};