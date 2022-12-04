#pragma once

#include "Vector.h"

struct Ray {
	Vector origin, direction;
	Ray(const Vector& origin, const Vector& direction) : origin(origin), direction(direction) {}
};