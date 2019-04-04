#pragma once
#include "MathLibrary.h"
#include "Ray.h"

class Light
{
public:

	Light(vec3 center, float _intensity);
	~Light();

	vec3 lightCenter;
	float lightIntensity;


};

