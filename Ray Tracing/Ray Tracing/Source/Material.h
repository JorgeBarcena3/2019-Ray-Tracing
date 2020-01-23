#pragma once
#include "MathLibrary.h"

/*
Clase que se encarga de definir un material en concreto
*/
class Material
{
public:

	/* 
	Constructor por defecto
	*/
	Material();

	/* 
	Destructor por defecto
	*/
	~Material();

	
	/* 
	Color base del material
	*/
	vec3 color;

	/* 
	Constante del valor difuso del material
	*/
	float diffuse;

	/* 
	Constante del valor especular del material
	*/
	float specular;

	/* 
	Multiplicador del especular
	*/
	float specularMultiplier;

	/* 
	Devuelve el color de un plano, segun las posiciones
	*/
	static vec3 getPlaneColor(float x, float z);


};

