#include "../headers/Ray.hpp"


Ray::Ray(vec3 _origin, vec3 _direction, float _life)
{
	origin = _origin;
	direction = _direction.normalize();
	life = _life;
}


Ray::~Ray()
{
}
