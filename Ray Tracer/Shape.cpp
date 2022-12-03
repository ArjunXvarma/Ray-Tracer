#include "Shape.h"

ShapeSet::~ShapeSet() {

}

ShapeSet::ShapeSet() {

}

void ShapeSet::addShape(Shape* shape) {
	shapes.push_back(shape);
}

bool ShapeSet::intersect(Intersection& intersection) {
	bool doesIntersect = false;

	for (std::vector<Shape*>::iterator iter = shapes.begin(); iter != shapes.end(); ++iter) {
		Shape* currShape = *iter;

		if (currShape->intersect(intersection))
			doesIntersect = true;
	}

	return doesIntersect;
}

bool ShapeSet::doesIntersect(const Ray& ray) {
	for (std::vector<Shape*>::iterator iter = shapes.begin(); iter != shapes.end(); ++iter) {
		Shape* currShape = *iter;

		if (currShape->doesIntersect(ray))
			return true;
	}

	return false;
}

Plane::Plane(const Point& position, const Vector& normal) 
	: position(position), normal(normal) {}

Plane::~Plane() {

}

bool Plane::intersect(Intersection& intersection) {
	// First we check if we intersect	
	float dDotN = dot(intersection.ray.direction, normal);

	if (dDotN == 0.0f)
		return false; // Ray is not embedded in the plane

	float t = dot(position - intersection.ray.origin, normal) / dDotN;

	if (t <= RAY_T_MIN || t >= intersection.t)
		return false; // outside relevant range

	intersection.t = t;
	intersection.pShape = this;

	return true;
}

bool Plane::doesIntersect(const Ray& ray) {
	// First check if we intersect 
	float dDotN = dot(ray.direction, normal);

	if (dDotN == 0.0f)
		return false; // Ray is not embedded in the plane

	float t = dot(position - ray.origin, normal) / dDotN;

	if (t <= RAY_T_MIN || t >= ray.tMax)
		return false; // outside relevant range

	return true;
}

Sphere::Sphere(const Point& center, float radius) 
	:center(center), radius(radius) {}

Sphere::~Sphere() {

}

bool Sphere::intersect(Intersection& intersection) {
	// Transform ray so we can consider origin centerd sphere
	Ray localRay = intersection.ray;
	localRay.origin -= center;

	// Calculate quadratic coefficients
	float a = localRay.direction.magnitudeSquared();
	float b = 2 * dot(localRay.direction, localRay.origin);
	float c = localRay.origin.magnitudeSquared() - sqr(radius);

	// Check whether we intersect
	float disc = sqr(b) - 4 * a * c;

	if (disc < 0.0f)
		return false;

	// Find the 2 intersection points, root1 close and root2 far
	float root1 = (-b - std::sqrt(disc)) / (2 * a);
	float root2 = (-b + std::sqrt(disc)) / (2 * a);

	if (root1 > RAY_T_MIN && root1 < intersection.t)
		intersection.t = root1;

	// change to else if, if the code doesn't work
	if (root2 > RAY_T_MIN && root2 < intersection.t)
		intersection.t = root2;
	
	else
		return false;

	// Finish populating the intersection
	intersection.pShape = this;

	return true;
}

bool Sphere::doesIntersect(const Ray& ray) {
	// Transform ray so we can consider origin centerd sphere
	Ray localRay = ray;
	localRay.origin -= center;

	// Calculate quadratic coefficients
	float a = localRay.direction.magnitudeSquared();
	float b = 2 * dot(localRay.direction, localRay.origin);
	float c = localRay.origin.magnitudeSquared() - sqr(radius);

	// Check whether we intersect
	float disc = sqr(b) - 4 * a * c;

	if (disc < 0.0f)
		return false;

	// Find the 2 intersection points, root1 close and root2 far
	float root1 = (-b - std::sqrt(disc)) / (2 * a);
	float root2 = (-b + std::sqrt(disc)) / (2 * a);

	if (root1 > RAY_T_MIN && root1 < ray.tMax)
		return true;

	else if (root2 > RAY_T_MIN && root2 < ray.tMax)
		return true;
	
	return false;
}
