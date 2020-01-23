#include "Box.h"

bool Box::hit(const Ray & ray, hit_record & record) const
{
	float tnear = -1000;
	float tfar = 1000;
	float t1, t2, tcube = 1;
	bool intersec = true;

	for (int i = 0; i < 3 && intersec; i++) {

		if (ray.direction.v[i] == 0) {
			if (ray.origin.v[i] < min.v[i] || ray.origin.v[i]  > max.v[i])
				return false;
		}
		else {

			t1 = (min.v[i] - ray.origin.m_X) / ray.direction.v[i];
			t2 = (max.v[i] - ray.origin.m_X) / ray.direction.v[i];
			if (t1 > t2) {
				float temp = t1;
				t1 = t2;
				t2 = temp;
			}

			if (t1 > tnear)
				tnear = t1;
			if (t2 < tfar)
				tfar = t2;
			if (tnear > tfar || tfar < 0) {
				intersec = false;
			}

			if (!intersec)
				tcube = -1;
			else
				tcube = tnear;			

		}

	
	}
		
	if (intersec) {
	
		vec3 center;
		for (int i = 0; i < 3; i++) {
			center.v[i] = (min.v[i] + max.v[i]) / 2;
		}

		record.pointAtRay = tcube;
		record.pointInWorld = ray.point_at_parametrer(record.pointAtRay);

		vec3 p = record.pointInWorld - center;

		vec3 d;
		for (int i = 0; i < 3; i++) {
			d.v[i] = abs(min.v[i] - max.v[i]) / 2;
		}

		record.normal = vec3((float)(p.m_X/d.m_X), (float)(p.m_Y / d.m_Y), (float)(p.m_Z / d.m_Z));

	
	}



	return intersec;
}


Box::Box(vec3 bound1, vec3 bound2, vec3 _color)
{
	min = bound1;
	max = bound2;
	myMaterial.color = _color;


}

Box::~Box()
{
}
