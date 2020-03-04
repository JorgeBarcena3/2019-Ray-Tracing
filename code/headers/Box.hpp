#pragma once
#include "MathLibrary.hpp"
#include "Ray.hpp"
#include "objectToTrace.hpp"

class Box : public objectToTrace
{
public:

	bool hit(const Ray& ray, hit_record& record) const;

	Box(vec3 _min, vec3 _max, vec3 _color);
	~Box();

	vec3 min, max;
};

