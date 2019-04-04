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
	void iluminateObject(float angle, vec3 & color);
	Ray getShadowRay(const hit_record & record);
	vec3 getColor(const Ray& ray, int depth = 0);
	void applyReflection(const hit_record& record, vec3& color, const Ray& ray, const int depth, const int i);

	Scene* myScene;

};


