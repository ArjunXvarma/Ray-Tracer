#include "Sphere.h"

Sphere::Sphere(const Vector& center, double radius) 
    : center(center), radius(radius) {}

Vector Sphere::getNormal(const Vector& pi) const { 
    return (pi - center) / radius; 
}

bool Sphere::intersect(const Ray& ray, double& t) const {
    const Vector o = ray.origin;
    const Vector d = ray.direction;
    const Vector oc = o - center;
    const double b = 2 * dot(oc, d);
    const double c = dot(oc, oc) - radius * radius;
    double disc = b * b - 4 * c;
    if (disc < 1e-4) return false;
    disc = sqrt(disc);
    const double t0 = -b - disc;
    const double t1 = -b + disc;
    t = (t0 < t1) ? t0 : t1;
    return true;
}