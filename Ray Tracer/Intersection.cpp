#include "Intersection.h"

Intersection::Intersection()
	: ray(), t(RAY_T_MAX), pShape(NULL) {}

Intersection::~Intersection() {

}

Intersection::Intersection(const Intersection& i)
	: ray(i.ray), t(i.t), pShape(i.pShape) {}

Intersection::Intersection(const Ray& ray)
	: ray(ray), t(ray.tMax), pShape(NULL) {}

Intersection& Intersection::operator=(const Intersection& i) {
	this->ray = i.ray;
	this->t = i.t;
	this->pShape = i.pShape;

	return *this;
}

bool Intersection::intersected() const {
	return (pShape != NULL);
}

Point Intersection::position() const {
	return ray.calculate(t);
}