#pragma once
#include "MathLibrary.hpp"
#include "Ray.hpp"

class Light
{
public:

	Light(vec3 center, float _intensity);
	~Light();

	vec3 lightCenter;
	float lightIntensity;


};

