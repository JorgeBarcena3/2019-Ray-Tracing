#include "../headers/Plane.hpp"
#include "../headers/Scene.hpp"
#include "../headers/objectToTrace.hpp"
#include <algorithm>



Plane::Plane(vec3 _normal, vec3 _point, vec3 _color)
{

	normal = _normal.normalize();
	point = _point;
	myMaterial.color = _color;
	myMaterial.diffuse = 1;

}

Plane::~Plane()
{
}

bool Plane::hit(const Ray& ray, hit_record& record) const
{

	float denominador = dot(normal, ray.direction);
	vec3 fixedPoint = point;
	fixedPoint *= -1.0f;
	float t = (normal.dot(ray.origin - fixedPoint)) / denominador;

	if (denominador == 0)
		return false;

	if (t > 0) {

		record.pointAtRay = t;
		record.pointInWorld = ray.point_at_parametrer(record.pointAtRay);
		record.normal = normal;
		return true;


	}

	return false;

}

vec3 Plane::getColor(hit_record record, Scene * scene) const
{
	vec3 baseColor =  Material::getPlaneColor(record.pointInWorld.m_X, record.pointInWorld.m_Z);

	vec3 N = (record.normal).normalize();
	vec3 L = (record.pointInWorld - scene->light->lightCenter).normalize() * -1;

	return (baseColor * myMaterial.diffuse * std::max(0.f, dot(N, L)));

}

