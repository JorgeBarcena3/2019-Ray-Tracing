#include "../headers/Material.hpp"

Material::Material()
{
	color = vec3();
	diffuse = 1.f;
	specular = 0.f;

}

Material::~Material()
{
}

vec3 Material::getPlaneColor(float x, float z)
{
	//Conversion and delete the decimal numbers
	int square = (int)x + (int)z;

	vec3 color;

	if (square % 2 == 0)
		color = vec3(255, 0, 0);
	else
		color = vec3(255, 255, 0);

	return color;

}
