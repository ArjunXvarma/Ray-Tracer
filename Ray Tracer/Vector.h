#pragma once

#include<cmath>

struct Vector {
    double x, y, z;
    Vector(double x, double y, double z);

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(double d) const;
    Vector operator/(double d) const;

    Vector normalize() const;
};

inline double dot(const Vector& a, const Vector& b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}