#include "Material.h"

Material::Material()
{
	texture = false;
	color = vec3();
	reflection = 0.0f;
	refraction = 0.0f;
}

Material::~Material()
{
}

vec3 Material::getColor(float x, float z)
{
	//Conversion and delete the decimal numbers
	int square = (int)x + (int)z;

	if (square % 2 == 0)
		color = vec3(255, 0, 0);
	else
		color = vec3(255, 255, 0);

	return color;

}
