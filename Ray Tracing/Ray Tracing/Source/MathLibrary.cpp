#include "MathLibrary.h"


//////////////
///VECTOR 2///
//////////////

vec2::vec2()
{
	m_X = 0;
	m_Y = 0;
}

vec2::vec2(float a_X, float a_Y)
{
	m_X = a_X;
	m_Y = a_Y;

}

vec2 & vec2::operator=(const vec2 & rhs)
{

	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	return *this;
}


vec2& vec2::operator+=(const vec2 &a_Rhs) {

	m_X += a_Rhs.m_X;
	m_Y += a_Rhs.m_Y;
	return *this;
}

vec2& vec2::operator-=(const vec2 &a_Rhs) {

	m_X += (a_Rhs.m_X * -1);
	m_Y += (a_Rhs.m_Y * -1);
	return *this;
}

vec2& vec2::operator*=(float a_Rhs) {

	m_X *= a_Rhs;
	m_Y *= a_Rhs;
	return *this;
}

vec2& vec2::operator/=(float a_Rhs) {

	m_X *= (1 / a_Rhs);
	m_Y *= (1 / a_Rhs);
	return *this;
}

float vec2::operator[](int a_Index) const {

	if (a_Index <= 1)
		return v[a_Index];
	else
		throw std::out_of_range("Error with the index " + a_Index);


}

float& vec2::operator[](int a_Index) {

	if (a_Index <= 1)
		return v[a_Index];
	else
		throw std::out_of_range("Error with the index " + a_Index);


}

vec2& vec2::normalize() {


	float magnitude = length();
	m_X = m_X / magnitude;
	m_Y = m_Y / magnitude;

	return *this;

}

vec2 operator+(const vec2 &a_Lhs, const vec2 &a_Rhs) {

	vec2 newVec;
	newVec.m_X = a_Lhs.m_X + a_Rhs.m_X;
	newVec.m_Y = a_Lhs.m_Y + a_Rhs.m_Y;
	return newVec;

}

vec2 operator-(const vec2 &a_Lhs, const vec2 &a_Rhs) {

	vec2 newVec;
	newVec.m_X = a_Lhs.m_X + (-1 * a_Rhs.m_X);
	newVec.m_Y = a_Lhs.m_Y + (-1 * a_Rhs.m_Y);
	return newVec;

}

vec2 operator*(const vec2 &a_Lhs, float a_Rhs) {

	vec2 newVec;
	newVec.m_X = a_Lhs.m_X * a_Rhs;
	newVec.m_Y = a_Lhs.m_Y * a_Rhs;
	return newVec;

}

vec2 operator/(const vec2 &a_Lhs, float a_Rhs) {

	vec2 newVec;
	newVec.m_X = a_Lhs.m_X *(1 / a_Rhs);
	newVec.m_Y = a_Lhs.m_Y *(1 / a_Rhs);
	return newVec;
}

bool operator==(const vec2 &a_Lhs, const vec2 &a_Rhs) {

	if (a_Lhs.m_X == a_Rhs.m_X && a_Lhs.m_Y == a_Rhs.m_Y)
		return true;
	else
		return false;
}

bool operator!=(const vec2 &a_Lhs, const vec2 &a_Rhs) {

	if (a_Lhs.m_X != a_Rhs.m_X || a_Lhs.m_Y != a_Rhs.m_Y)
		return true;
	else
		return false;
}

//////////////
///VECTOR 3///
//////////////

vec3::vec3() {

	m_X = m_Z = m_Y = 0;
}

vec3::vec3(float a_X, float a_Y, float a_Z) {

	m_X = a_X;
	m_Y = a_Y;
	m_Z = a_Z;

}

vec3& vec3::operator=(const vec3& rhs) {

	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	m_Z = rhs.m_Z;
	return *this;
}

vec3& vec3::operator+=(const vec3 &a_Rhs) {

	m_X += a_Rhs.m_X;
	m_Y += a_Rhs.m_Y;
	m_Z += a_Rhs.m_Z;
	return *this;
}

vec3& vec3::operator-=(const vec3 &a_Rhs) {

	m_X -= a_Rhs.m_X;
	m_Y -= a_Rhs.m_Y;
	m_Z -= a_Rhs.m_Z;
	return *this;
}

vec3& vec3::operator*=(float a_Rhs) {

	m_X *= a_Rhs;
	m_Y *= a_Rhs;
	m_Z *= a_Rhs;
	return *this;

}

vec3& vec3::operator/=(float a_Rhs) {

	m_X *= (1 / a_Rhs);
	m_Y *= (1 / a_Rhs);
	m_Z *= (1 / a_Rhs);
	return *this;
}

float vec3::operator[](int a_Index) const {


	if (a_Index <= 2)
		return v[a_Index];
	else
		throw std::out_of_range("Error with the index " + a_Index);

}

float& vec3::operator[](int a_Index) {

	if (a_Index <= 2)
		return v[a_Index];
	else
		throw std::out_of_range("Error with the index " + a_Index);

}

vec3& vec3::normalize() {

	float magnitude = length();
	m_X = m_X / magnitude;
	m_Y = m_Y / magnitude;
	m_Z = m_Z / magnitude;

	return *this;

}

vec3 & vec3::colorClip()
{
	double max = 0;
	for (double x : v) {

		if (x >= max)
			max = x;

	}
	for (double x : v) {

		x = x * 256 / max;

	}

	return *this;
}

vec3 vec3::scalar(float scalar)
{
	return vec3(r * scalar, g*scalar, b*scalar);;
}

vec3 operator+(const vec3 &a_Lhs, const vec3 &a_Rhs) {

	vec3 newVec;
	newVec.m_X = a_Lhs.m_X + a_Rhs.m_X;
	newVec.m_Y = a_Lhs.m_Y + a_Rhs.m_Y;
	newVec.m_Z = a_Lhs.m_Z + a_Rhs.m_Z;
	return newVec;

}

vec3 operator-(const vec3 &a_Lhs, const vec3 &a_Rhs) {

	vec3 newVec;
	newVec.m_X = a_Lhs.m_X - a_Rhs.m_X;
	newVec.m_Y = a_Lhs.m_Y - a_Rhs.m_Y;
	newVec.m_Z = a_Lhs.m_Z - a_Rhs.m_Z;
	return newVec;
}

vec3 operator*(const vec3 &a_Lhs, float a_Rhs) {

	vec3 newVec;
	newVec.m_X = a_Lhs.m_X * a_Rhs;
	newVec.m_Y = a_Lhs.m_Y * a_Rhs;
	newVec.m_Z = a_Lhs.m_Z * a_Rhs;
	return newVec;
}

vec3 operator/(const vec3 &a_Lhs, float a_Rhs) {

	vec3 newVec;
	newVec.m_X = a_Lhs.m_X *(1 / a_Rhs);
	newVec.m_Y = a_Lhs.m_Y *(1 / a_Rhs);
	newVec.m_Z = a_Lhs.m_Z *(1 / a_Rhs);
	return newVec;
}

bool operator==(const vec3 &a_Lhs, const vec3 &a_Rhs) {

	if (a_Lhs.m_X == a_Rhs.m_X && a_Lhs.m_Y == a_Rhs.m_Y && a_Lhs.m_Z == a_Rhs.m_Z)
		return true;
	else
		return false;
}

bool operator!=(const vec3 &a_Lhs, const vec3 &a_Rhs) {

	if (a_Lhs.m_X == a_Rhs.m_X && a_Lhs.m_Y == a_Rhs.m_Y && a_Lhs.m_Z == a_Rhs.m_Z)
		return false;
	else
		return true;

}


/////////////
////MAT 4////
/////////////

mat4::mat4() {

	for (int i = 0; i < 16; i++)
		m[i] = 0;

}

mat4::mat4(vec3 a_Row0, float a_03,
	vec3 a_Row1, float a_13,
	vec3 a_Row2, float a_23,
	vec3 a_Row3, float a_33) {

	int i = 0;

	for (; i < 3; i++)
		m[i] = a_Row0[i];
	m[3] = a_03;
	i++;

	for (int j = 0; j < 3; j++, i++)
		m[i] = a_Row1[j];
	m[7] = a_13;
	i++;

	for (int j = 0; j < 3; j++, i++)
		m[i] = a_Row2[j];
	m[11] = a_23;
	i++;

	for (int j = 0; j < 3; j++, i++)
		m[i] = a_Row3[j];
	m[15] = a_33;
	i++;

}

mat4::mat4(float a_00, float a_01, float a_02, float a_03,
	float a_10, float a_11, float a_12, float a_13,
	float a_20, float a_21, float a_22, float a_23,
	float a_30, float a_31, float a_32, float a_33) {

	m[0] = a_00;
	m[1] = a_01;
	m[2] = a_02;
	m[3] = a_03;
	///////////////////
	m[4] = a_10;
	m[5] = a_11;
	m[6] = a_12;
	m[7] = a_13;
	///////////////////
	m[8] = a_20;
	m[9] = a_21;
	m[10] = a_22;
	m[11] = a_23;
	///////////////////
	m[12] = a_30;
	m[13] = a_31;
	m[14] = a_32;
	m[15] = a_33;

}
mat4 & mat4::operator=(const mat4 & rhs)
{
	for (int i = 0; i < 16; i++)
		m[i] = rhs[i];

	return *this;
}


mat4& mat4::operator+=(const mat4 &a_Rhs) {

	for (int i = 0; i < 16; i++)
		m[i] += a_Rhs[i];

	return *this;
}


mat4& mat4::operator-=(const mat4 &a_Rhs) {

	for (int i = 0; i < 16; i++)
		m[i] -= a_Rhs[i];

	return *this;
}

mat4& mat4::operator*=(const mat4 &a_Rhs) {

	mat4 myNewMat = mat4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				myNewMat[j + i * 4] += m[k + i * 4] * a_Rhs[j + k * 4];
			}
		}
	}

	for (int i = 0; i < 16; i++)
		m[i] = myNewMat[i];

	return *this;
}

float mat4::operator[](int a_Index) const
{
	if (a_Index <= 15)
		return m[a_Index];
	else
		throw std::out_of_range("Error with the index " + a_Index);
}

float& mat4::operator[](int a_Index)
{
	if (a_Index <= 15)
		return m[a_Index];
	else
		throw std::out_of_range("Error with the index " + a_Index);
}


float determinantRecursive(float matrix[4][4], int size) {

	float det = 0;
	float signOfMinor = 1;
	float temp[4][4];
	int itemp = 0;
	int jtemp = 0;

	if (size == 1)
		return matrix[0][0];
	else {

		for (int columns = 0; columns < size; columns++) {

			itemp = jtemp = 0;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {

					temp[i][j] = 0;
					if (i != 0 && j != columns) {

						temp[itemp][jtemp] = matrix[i][j];
						if (jtemp < (size - 2))
						{
							jtemp++;
						}
						else
						{
							jtemp = 0;
							itemp++;
						}

					}
				}
			}

			det += signOfMinor * (matrix[0][columns] * determinantRecursive(temp, size - 1));
			signOfMinor = -1 * signOfMinor;

		}

	}

	return det;

}


float mat4::determinant() const {

	//Mat4 to a bidimensional array
	int index = 0;
	float matrix[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, index++) {

			matrix[i][j] = m[index];

		}
	}

	//Call determinantRecursive
	float det = determinantRecursive(matrix, 4);


	return det;

}

mat4& mat4::inverse() {


	//Obtain the det
	float det = determinant();

	//Matrix Coofactor

	mat4 cofactors;

	cofactors.m_00 = m[5] * m[10] * m[15] + m[9] * m[14] * m[7] + m[13] * m[6] * m[11] -
		(m[7] * m[10] * m[13] + m[6] * m[9] * m[15] + m[14] * m[11] * m[5]);

	cofactors.m_01 = -1 * (m[4] * m[10] * m[15] + m[8] * m[14] * m[7] + m[12] * m[6] * m[11] -
		(m[7] * m[10] * m[12] + m[6] * m[8] * m[15] + m[14] * m[11] * m[4]));

	cofactors.m_02 = m[4] * m[9] * m[15] + m[8] * m[13] * m[7] + m[12] * m[5] * m[11] -
		(m[7] * m[9] * m[12] + m[5] * m[8] * m[15] + m[13] * m[11] * m[4]);

	cofactors.m_03 = -1 * (m[4] * m[9] * m[14] + m[8] * m[13] * m[6] + m[12] * m[5] * m[10] -
		(m[6] * m[9] * m[12] + m[5] * m[8] * m[14] + m[13] * m[10] * m[4]));

	cofactors.m_10 = -1 * (m[1] * m[10] * m[15] + m[9] * m[14] * m[3] + m[13] * m[2] * m[11] -
		(m[3] * m[10] * m[13] + m[2] * m[9] * m[15] + m[14] * m[11] * m[1]));

	cofactors.m_11 = m[0] * m[10] * m[15] + m[8] * m[14] * m[3] + m[12] * m[2] * m[11] -
		(m[3] * m[10] * m[12] + m[2] * m[8] * m[15] + m[14] * m[11] * m[0]);

	cofactors.m_12 = -1 * (m[0] * m[9] * m[15] + m[8] * m[13] * m[3] + m[12] * m[1] * m[11] -
		(m[3] * m[9] * m[12] + m[1] * m[8] * m[15] + m[13] * m[11] * m[0]));

	cofactors.m_13 = m[0] * m[9] * m[14] + m[8] * m[13] * m[2] + m[12] * m[1] * m[10] -
		(m[2] * m[9] * m[12] + m[1] * m[8] * m[14] + m[13] * m[10] * m[0]);

	cofactors.m_20 = m[1] * m[6] * m[15] + m[5] * m[14] * m[3] + m[2] * m[7] * m[13] -
		(m[3] * m[6] * m[13] + m[7] * m[14] * m[1] + m[5] * m[2] * m[15]);

	cofactors.m_21 = -1 * (m[0] * m[6] * m[15] + m[4] * m[14] * m[3] + m[2] * m[7] * m[12] -
		(m[3] * m[6] * m[12] + m[7] * m[14] * m[0] + m[4] * m[2] * m[15]));

	cofactors.m_22 = m[0] * m[5] * m[15] + m[4] * m[13] * m[3] + m[1] * m[7] * m[12] -
		(m[3] * m[5] * m[12] + m[7] * m[13] * m[0] + m[4] * m[1] * m[15]);

	cofactors.m_23 = -1 * (m[0] * m[5] * m[14] + m[4] * m[13] * m[2] + m[1] * m[6] * m[12] -
		(m[2] * m[5] * m[12] + m[6] * m[13] * m[0] + m[4] * m[1] * m[14]));

	cofactors.m_30 = -1 * (m[1] * m[6] * m[11] + m[5] * m[3] * m[10] + m[9] * m[2] * m[7] -
		(m[3] * m[6] * m[9] + m[7] * m[10] * m[1] + m[5] * m[2] * m[11]));

	cofactors.m_31 = m[0] * m[6] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] -
		(m[3] * m[6] * m[8] + m[7] * m[10] * m[0] + m[4] * m[2] * m[11]);

	cofactors.m_32 = -1 * (m[0] * m[5] * m[11] + m[4] * m[3] * m[9] + m[8] * m[1] * m[7] -
		(m[3] * m[5] * m[8] + m[7] * m[9] * m[0] + m[4] * m[1] * m[11]));

	cofactors.m_33 = m[0] * m[5] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] -
		(m[2] * m[5] * m[8] + m[6] * m[9] * m[0] + m[4] * m[1] * m[10]);


	//Mat4 to a bidimensional array
	int index = 0;
	float matrixCofactors[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, index++) {

			matrixCofactors[i][j] = cofactors.m[index];

		}
	}

	//Traspose Matrix
	float matrixTrasposed[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrixTrasposed[i][j] = matrixCofactors[j][i];
		}
	}

	//Trasposed matrix to a mat4
	mat4 b;

	index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, index++) {

			b.m[index] = matrixTrasposed[i][j];

		}
	}


	//SAVE THE MATRIX
	for (int i = 0; i < 16; i++)
		m[i] = b.m[i]/det;


	return *this;

};



mat4 mat4::identity()
{
	return mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

mat4 mat4::rotateX(float a_Radians)
{
	float cosX = cos(a_Radians);
	float senX = sin(a_Radians);

	mat4 rotationMat(
		1, 0, 0, 0,
		0, cosX, -senX, 0,
		0, senX, cosX, 0,
		0, 0, 0, 1);

	mat4 rotated = identity() * rotationMat;
	return rotated;
}

mat4 mat4::rotateY(float a_Radians)
{
	float cosX = cos(a_Radians);
	float senX = sin(a_Radians);

	mat4 rotationMat(
		cosX, 0, senX, 0,
		0, 1, 0, 0,
		-senX, 0, cosX, 0,
		0, 0, 0, 1);

	mat4 rotated = identity() * rotationMat;
	return rotated;
}

mat4 mat4::rotateZ(float a_Radians)
{
	float cosX = cos(a_Radians);
	float senX = sin(a_Radians);

	mat4 rotationMat(
		cosX, -senX, 0, 0,
		senX, cosX, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	mat4 rotated = identity() * rotationMat;
	return rotated;
}

mat4 mat4::translate(const vec3 & a_Translation)
{

	mat4 traslated(
		1.0f, 0.0f, 0.0f, a_Translation.m_X,
		0.0f, 1.0f, 0.0f, a_Translation.m_Y,
		0.0f, 0.0f, 1.0f, a_Translation.m_Z,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	return traslated;
}
//
//mat4 mat4::lookat(const vec3 & a_Eye, const vec3 & a_Center, const vec3 & a_Up)
//{
//
//	//vec3 f = (a_Center - a_Eye).normalize();
//	//vec3 u = a_Up;
//	//u.normalize();
//	//vec3 signOfMinor = (f.cross(u)).normalize();
//	//u = signOfMinor.cross(f);
//
//
//	//return mat4(signOfMinor.m_X, signOfMinor.m_Y, signOfMinor.m_Z, 0,
//	//	u.m_X, u.m_Y, u.m_Z, 0,
//	//	-f.m_X, -f.m_Y, -f.m_Z, 0,
//	//	-signOfMinor.dot(a_Eye), -u.dot(a_Eye), -f.dot(a_Eye), 1);
//	return identity();
//}
//
//mat4 mat4::projection(float a_FovY, float a_AspectRatio, float a_Near, float a_Far)
//{
//	return mat4();
//}

mat4 operator+(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	mat4 myNewMat;

	for (int i = 0; i < 16; i++)
		myNewMat[i] = a_Lhs[i] + a_Rhs[i];

	return myNewMat;
}

mat4 operator-(const mat4 & a_Lhs, const mat4 & a_Rhs)
{
	mat4 myNewMat;

	for (int i = 0; i < 16; i++)
		myNewMat[i] = a_Lhs[i] + (-1 * a_Rhs[i]);

	return myNewMat;
}

mat4 operator*(const mat4 & a_Lhs, const mat4 & a_Rhs)
{

	//Mat4 A to a bidimensional array
	int index = 0;
	float matrixA[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, index++) {

			matrixA[i][j] = a_Lhs.m[index];

		}
	}

	//Mat4 B to a bidimensional array
	index = 0;
	float matrixB[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, index++) {

			matrixB[i][j] = a_Rhs.m[index];

		}
	}

	//Mult the matrices
	float mult[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mult[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				mult[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}

	//Mult arr to mat4
	mat4 newMat;
	index = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, index++) {

			newMat.m[index] = mult[i][j];

		}
	}


	return newMat;
}

vec3 operator*(const mat4 & a_Lhs, const vec3 & a_Rhs)
{
	vec3 result;

	result.m_X = a_Lhs.m_00*a_Rhs.m_X + a_Lhs.m_01*a_Rhs.m_Y + a_Lhs.m_02*a_Rhs.m_Z;
	result.m_Y = a_Lhs.m_10*a_Rhs.m_X + a_Lhs.m_11*a_Rhs.m_Y + a_Lhs.m_12*a_Rhs.m_Z;
	result.m_Z = a_Lhs.m_20*a_Rhs.m_X + a_Lhs.m_21*a_Rhs.m_Y + a_Lhs.m_22*a_Rhs.m_Z;

	return result;
}


vec3 operator*(const vec3 & a_Rhs, const mat4 & a_Lhs)
{
	vec3 myNewVector;

	myNewVector.m_X = (a_Rhs.m_X * a_Lhs[0]) * (a_Rhs.m_Y * a_Lhs[4]) * (a_Rhs.m_Z * a_Lhs[8]);
	myNewVector.m_Y = (a_Rhs.m_X * a_Lhs[1]) * (a_Rhs.m_Y * a_Lhs[5]) * (a_Rhs.m_Z * a_Lhs[9]);
	myNewVector.m_Z = (a_Rhs.m_X * a_Lhs[2]) * (a_Rhs.m_Y * a_Lhs[6]) * (a_Rhs.m_Z * a_Lhs[10]);

	return myNewVector;
}
