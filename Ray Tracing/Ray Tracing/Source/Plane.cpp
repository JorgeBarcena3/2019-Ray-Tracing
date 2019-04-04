#include "Plane.h"



Plane::Plane(vec3 _normal, vec3 _point, vec3 _color, bool _texture)
{

	normal = _normal.normalize();
	point = _point;
	myMaterial.color = _color;
	myMaterial.texture = _texture;
	myMaterial.reflection = 0;

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

