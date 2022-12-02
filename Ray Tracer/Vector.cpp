#include "Vector.h"

inline float sqr(float x) {
	return x * x;
}

Vector::Vector() 
	: x(0.0f), y(0.0f), z(0.0f) {}

Vector::Vector(const Vector& v) 
	: x(v.x), y(v.y), z(v.z) {}

Vector::Vector(float x, float y, float z)
	: x(x), y(y), z(z) {}

Vector::Vector(float a)
	: x(a), y(a), z(a) {}

inline float Vector::magnitude() {
	return sqrt(magnitudeSquare());
}

inline float Vector::magnitudeSquare() {
	return sqr(x) + sqr(y) + sqr(z);
}

float Vector::normalise() {
	*this /= magnitude();

	return magnitude();
}

Vector Vector::normalised() {
	Vector v(*this);
	v.normalise();
	return v;
}

Vector& Vector::operator=(const Vector& v) {
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}
Vector& Vector::operator+=(const Vector& v) {
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

Vector& Vector::operator-=(const Vector& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}
Vector& Vector::operator*=(float f) {
	x *= f;
	y *= f;
	z *= f;

	return *this;
}
Vector& Vector::operator/=(float f) {
	x /= f;
	y /= f;
	z /= f;

	return *this;
}

Vector Vector::operator-() const {
	return Vector(-x, -y, -z);
}

float dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector cross(Vector a, Vector b) {
	return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

inline Vector operator+(const Vector& a, const Vector& b) {
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector operator-(const Vector& a, const Vector& b) {
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vector operator*(const Vector& a, const Vector& b) {
	return Vector(a.x * b.x, a.y * b.y, a.z * b.z);
}

inline Vector operator*(const Vector& a, float f) {
	return Vector(a.x * f, a.y * f, a.z * f);
}
inline Vector operator*(float f, const Vector& a) {
	return Vector(a.x * f, a.y * f, a.z * f);
}
inline Vector operator/(const Vector& a, const Vector& b) {
	return Vector(a.x / b.x, a.y / b.y, a.z / b.z);
}
inline Vector operator/(const Vector& a, float f) {
	return Vector(a.x / f, a.y / f, a.z / f);
}

inline Vector operator/(float f, const Vector& a) {
	return Vector(f / a.x, f / a.y, f / a.z);
}

Vector2::Vector2() 
	: u(0.0f), v(0.0f) {}

Vector2::Vector2(const Vector2& v)
	: u(v.u), v(v.v) {}

Vector2::Vector2(float u, float v)
	: u(u), v(v) {}

Vector2::Vector2(float f)
	: u(f), v(f) {}

Vector2& Vector2::operator=(const Vector2& v) {
	this->u = v.u;
	this->v = v.v;

	return *this;
}