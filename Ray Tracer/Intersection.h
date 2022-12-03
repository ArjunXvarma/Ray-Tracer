#pragma once

#ifndef  RAY_H
#include "Ray.h"
#include "Shape.h"

struct Intersection {
	Ray ray;
	float t;
	Shape* pShape;

	Intersection();
	Intersection(const Intersection& i);
	Intersection(const Ray& ray);

	virtual ~Intersection();

	Intersection& operator=(const Intersection& i);

	bool intersected() const;
	Point position() const;
};

#endif // ! RAY_H