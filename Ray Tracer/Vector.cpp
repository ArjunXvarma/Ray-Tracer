#include "Vector.h"

Vector::Vector(double x, double y, double z) 
    : x(x), y(y), z(z) {}

Vector Vector::operator+(const Vector& v) const { 
    return Vector(x + v.x, y + v.y, z + v.z); 
}

Vector Vector::operator-(const Vector& v) const {
    return Vector(x - v.x, y - v.y, z - v.z); 
}

Vector Vector::operator*(double d) const { 
    return Vector(x * d, y * d, z * d); 
}

Vector Vector::operator/(double d) const { 
    return Vector(x / d, y / d, z / d); 
}

Vector Vector::normalize() const {
    double mg = sqrt(x * x + y * y + z * z);
    return Vector(x / mg, y / mg, z / mg);
}

