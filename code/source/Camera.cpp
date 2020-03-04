#include "../headers/Camera.hpp"

Camera::Camera(vec3 _origin)
{
	origin = _origin;
	lowerLeftCorner = vec3(origin.m_X - 2, origin.m_Y - 1, origin.m_Z - 1);
	vertical = vec3(origin.m_X, origin.m_Y + 2, origin.m_Z);
	horizontal = vec3(origin.m_X + 4, origin.m_Y, origin.m_Z);

}


Camera::~Camera()
{
}

Ray Camera::getRay(float x, float y) {

	return Ray(origin, lowerLeftCorner + (horizontal * x) + (vertical * (y) - origin));

}
