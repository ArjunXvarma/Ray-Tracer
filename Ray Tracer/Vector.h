#ifndef VECTOR_H
#define VECTOR_H

#include<math.h>

inline float sqr(float x);

class Vector
{
public:
	float x, y, z;
	Vector();
	Vector(const Vector& v);
	Vector(float x, float y, float z);
	Vector(float a);

	virtual ~Vector();

	inline float magnitude();
	inline float magnitudeSquared();

	float normalise();
	Vector normalised();

	Vector& operator=(const Vector& v);
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector& operator*=(float f);
	Vector& operator/=(float f);
	Vector operator-() const;
};

float dot(Vector a, Vector b);
Vector cross(Vector a, Vector b);

inline Vector operator+(const Vector& a, const Vector& b);
inline Vector operator-(const Vector& a, const Vector& b);
inline Vector operator*(const Vector& a, const Vector& b);
inline Vector operator*(const Vector& a, float f);
inline Vector operator*(float f, const Vector& a);
inline Vector operator/(const Vector& a, const Vector& b);
inline Vector operator/(const Vector& a, float f);
inline Vector operator/(float f, const Vector& a);

typedef Vector Point;

class Vector2 {
public:
	float u, v;

	Vector2();
	Vector2(const Vector2& v);
	Vector2(float u, float v);
	Vector2(float f);

	virtual ~Vector2();

	Vector2& operator=(const Vector2& v);
};

#endif // !VECTOR_H

