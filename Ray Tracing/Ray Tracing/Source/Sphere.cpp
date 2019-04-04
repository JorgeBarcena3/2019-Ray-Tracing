#include "Sphere.h"

bool Sphere::hit(const Ray& ray, hit_record& record) const
{

	//Analytic Solution
	vec3 rayToCenterDirection = ray.origin - centerSphere;
	float a = dot(ray.direction, ray.direction);
	float b = 2.0f * dot(rayToCenterDirection, ray.direction);
	float c = dot(rayToCenterDirection, rayToCenterDirection) - (radius * radius);

	float discriminant_in_equation = (b * b) - (4 * a * c);
	if (discriminant_in_equation > 0.0f)
	{
		float t = (-b - sqrt(discriminant_in_equation)) / (2.0f * a);
		if (t > 0.0f)
		{
			record.pointAtRay = t;
			record.pointInWorld = ray.point_at_parametrer(record.pointAtRay);
			record.normal = (record.pointInWorld - centerSphere) / radius;
			record.normal.normalize();
			return true;
		}

		t = (-b + sqrt(discriminant_in_equation)) / (2.0f * a);
		if (t > 0)
		{
			record.pointAtRay = t;
			record.pointInWorld = ray.point_at_parametrer(record.pointAtRay);
			record.normal = (record.pointInWorld - centerSphere) / radius;
			record.normal.normalize();
			return true;
		}
	}

	return false;

}


Sphere::Sphere(vec3 m_center, float m_radius, vec3 m_color) {

	centerSphere = m_center;
	radius = m_radius;
	myMaterial.color = m_color;
	myMaterial.texture = false;


}


Sphere::~Sphere()
{
}
