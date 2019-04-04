#pragma once
#include "MathLibrary.h"

class Ray
{
public:

	vec3 origin;
	vec3 direction;

	Ray();
	Ray(vec3 _origin, vec3 _direction);
	~Ray();
	inline vec3 point_at_parametrer(float t) const { return origin + direction * t; }


};

