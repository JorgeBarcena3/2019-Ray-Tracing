#pragma once
#include "MathLibrary.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Box.hpp"
#include "objectToTrace.hpp"
#include "light.hpp"
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
