#pragma once
#include "Render.h"

using namespace std;


Render::Render()
{
}


Render::~Render()
{
}

bool Render::setProyectedShadow(const Ray& ray) {

	bool hit = false;
	hit_record sh;
	for (int i = 0; i < myScene->objectsToTrace.size() && !hit; i++)
		hit = myScene->objectsToTrace[i]->hit(ray, sh);

	return hit;

}

void  Render::iluminateObject(float angle, vec3 & color) {


	if (angle <= 0)
		color = vec3(0, 0, 0);

	color = color.scalar(angle / (360 * myScene->light->lightIntensity));


}

Ray Render::getShadowRay(const hit_record & record) {

	vec3 newDirection = myScene->light->lightCenter - record.pointInWorld;
	newDirection.normalize();
	return Ray(record.pointInWorld + record.normal * 0.1f, newDirection);


}

vec3 Render::getColor(const Ray & ray, int depth)
{

	if (depth < 5) {

		double currentDepthIndex = DBL_MAX;
		vec3 color;
		hit_record record;

		bool hit = false;

		for (int i = 0; i < myScene->objectsToTrace.size(); i++) {

			if (myScene->objectsToTrace[i]->hit(ray, record)) {

				hit = true;

				if (record.pointAtRay < currentDepthIndex) {

					//Base color
					currentDepthIndex = record.pointAtRay;

					color = myScene->objectsToTrace[i]->myMaterial.texture ?
						myScene->objectsToTrace[i]->myMaterial.getColor(record.pointInWorld.m_X, record.pointInWorld.m_Z) :
						myScene->objectsToTrace[i]->myMaterial.color;

					//Proyected shadow
					Ray rayLight = getShadowRay(record);
					bool shadow = setProyectedShadow(rayLight);

					if (shadow)
						color = color.scalar(0.05f);

					float angle = record.normal.dot(rayLight.direction);
					angle = angle * 180 / 3.14f;
					iluminateObject(angle, color);


					//Reflection
					if (myScene->objectsToTrace[i]->myMaterial.reflection > 0)
						applyReflection(record, color, ray, depth, i);


					//Reflraction is not working
					if (myScene->objectsToTrace[i]->myMaterial.refraction > 0) {

						float n = (myScene->objectsToTrace[i]->myMaterial.refraction);
						float NormalDotLight = rayLight.direction.dot(record.normal);
						if (NormalDotLight < 0) {
							vec3 c1 = (rayLight.direction + record.normal * (rayLight.direction.dot(record.normal))) * n;
							vec3 c2 = record.normal * sqrt(1 - ((n * n) * (1 - NormalDotLight * NormalDotLight)));
							vec3 newAngle = c1 - c2;
							newAngle.normalize();
							Ray refractionRay = Ray(record.pointInWorld + vec3(0.05f, 0.05f, 0.05f), newAngle);
							color += getColor(refractionRay, depth + 1) * 0.5;
						}
						else {

							record.normal *= -1;
							vec3 c1 = (rayLight.direction + record.normal * (rayLight.direction.dot(record.normal))) * n;
							vec3 c2 = record.normal * sqrt(1 - ((n * n) * (1 - NormalDotLight * NormalDotLight)));
							vec3 newAngle = c1 - c2;
							newAngle.normalize();
							Ray refractionRay = Ray(record.pointInWorld + vec3(0.05f, 0.05f, 0.05f), newAngle);
							hit_record Kreflection;
							color += getColor(refractionRay, depth + 1) * 0.5;


						}
					}

				}
			}
		}

		if (hit) {

			color.colorClip();
			return color;
		}

		return myScene->backgroundColor;
	}

	return myScene->backgroundColor;
}

void Render::applyReflection(const hit_record & record, vec3 & color, const Ray & ray, const int depth, const int i)
{
	vec3 R = ray.direction - record.normal * ray.direction.dot(record.normal) * 2;
	R.normalize();
	Ray reflectionRay = Ray(record.pointInWorld + record.normal, R);
	color += getColor(reflectionRay, depth + 1) * myScene->objectsToTrace[i]->myMaterial.reflection;

}



