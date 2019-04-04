#pragma once
#include "Ray.h"
#include "material.h"

struct hit_record {

	float pointAtRay;
	vec3 pointInWorld;
	vec3 normal;
	
};


class objectToTrace
{

public:

	Material myMaterial;
	virtual bool hit(const Ray& ray, hit_record& record) const = 0;

};

