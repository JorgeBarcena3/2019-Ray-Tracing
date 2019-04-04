#pragma once
#include "MathLibrary.h"
#include "Ray.h"
#include "objectToTrace.h"

class Plane : public objectToTrace
{
public:

	//Plane(vec3 normal, float point, vec3 leftDown, vec3 leftUp, vec3 rightDown, vec3 rightUp,  vec3 color);
	Plane(vec3 _normal, vec3 _point, vec3 _color, bool _texture);
	~Plane();

	bool hit(const Ray& ray, hit_record& record) const;
	vec3 point;
	vec3 normal;


};

