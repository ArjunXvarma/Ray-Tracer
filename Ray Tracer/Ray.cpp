#include "Ray.h"

Ray::Ray()
	: origin(0.0f, 0.0f, 0.0f), direction(), tMax(RAY_T_MAX) {}

Ray::~Ray() {}

Ray::Ray(const Ray& ray)
	: origin(ray.origin), direction(ray.direction), tMax(ray.tMax) {}

Ray::Ray(const Point& origin, const Vector& direction, float tMax = RAY_T_MAX)
	: origin(origin), direction(direction), tMax(tMax) {}

Ray& Ray::operator=(const Ray& ray) {
	origin = ray.origin;
	direction = ray.direction;
	tMax = ray.tMax;

	return *this;
}

Point Ray::calculate(float t) const {
	return origin + direction * t;
}