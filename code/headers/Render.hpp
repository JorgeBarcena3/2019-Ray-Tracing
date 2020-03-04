#pragma once
#include "MathLibrary.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
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


