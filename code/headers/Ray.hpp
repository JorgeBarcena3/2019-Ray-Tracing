#pragma once
#include "MathLibrary.hpp"

class Ray
{
public:

	vec3 origin;
	vec3 direction;
	float life;

	Ray(vec3 _origin, vec3 _direction, float life = 100);
	~Ray();
	inline vec3 point_at_parametrer(float t) const { return origin + direction * t; }


};

