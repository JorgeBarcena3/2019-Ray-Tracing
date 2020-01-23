#pragma once
#include "MathLibrary.h"
#include "Ray.h"
#include "Scene.h"
#include <vector>

class Render
{
public:

	Render();
	~Render();

	bool setProyectedShadow(const Ray & ray);
	Ray getShadowRay(const hit_record & record);
	vec3 getColor(Ray& ray);
	vec3 applyReflection(const hit_record& record, Ray& ray);

	Scene* myScene;

};


