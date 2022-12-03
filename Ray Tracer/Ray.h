#pragma once

#include "Vector.h"

#define RAY_T_MIN 0.0001f
#define RAY_T_MAX 1.0e30f

struct Ray
{
	Point origin; // Start
	Vector direction;
	float tMax;

	Ray();
	Ray(const Ray& ray);
	Ray(const Point& origin, const Vector& direction, float tMax = RAY_T_MAX);

	virtual ~Ray();

	Ray& operator=(const Ray& ray);
	
	Point calculate(float t) const;
};
