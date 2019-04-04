#pragma once
#include "MathLibrary.h"
class Material
{
public:

	Material();
	~Material();
	vec3 getColor(float x, float z);
	bool texture;
	vec3 color;
	float reflection;
	float refraction;

};

