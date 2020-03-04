#pragma once
#include "MathLibrary.hpp"
#include "Ray.hpp"

class Camera
{
public:

	Camera(vec3 origin);
	~Camera();
	Ray getRay(float x, float y);


private:

	vec3 origin;
	vec3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;


};

