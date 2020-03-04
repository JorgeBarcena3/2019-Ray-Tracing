#pragma once
#include "Ray.hpp"
#include "material.hpp"


struct hit_record {

	float pointAtRay;
	vec3 pointInWorld;
	vec3 normal;
	
};


class Scene;

class objectToTrace
{

public:

	Material myMaterial;

	virtual bool hit(const Ray& ray, hit_record& record) const = 0;

	virtual vec3 getColor(hit_record record, Scene * scene) const = 0;

};

