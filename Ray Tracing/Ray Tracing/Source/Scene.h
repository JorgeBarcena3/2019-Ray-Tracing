#pragma once
#include "MathLibrary.h"
#include "Sphere.h"
#include "Plane.h"
#include "Box.h"
#include "objectToTrace.h"
#include "light.h"
#include <vector>

class Scene
{
public:

	std::vector <objectToTrace*> objectsToTrace;

	Light* light;

	const vec3 backgroundColor = vec3(153, 153, 153);

	vec3 ambientLight = vec3(0,0,0);

	~Scene() {
	
		delete light;
		for (objectToTrace* obj : objectsToTrace)
			delete obj;	
	
	}

};
