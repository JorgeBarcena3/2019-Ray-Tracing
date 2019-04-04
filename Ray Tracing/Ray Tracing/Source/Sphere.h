#pragma once
#include "MathLibrary.h"
#include "Ray.h"
#include "objectToTrace.h"

class Sphere : public objectToTrace
{
public:

	vec3 centerSphere;
	float radius;

	bool hit(const Ray& ray, hit_record& record) const;

	Sphere(vec3 center, float m_radius, vec3 color);
	~Sphere();
};


