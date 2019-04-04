#include "Ray.h"


Ray::Ray()
{
}

Ray::Ray(vec3 _origin, vec3 _direction)
{
	origin = _origin;
	direction = _direction.normalize();
}


Ray::~Ray()
{
}
