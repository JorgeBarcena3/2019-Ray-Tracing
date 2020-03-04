#pragma once
#include <stdexcept>

class vec2
{
public:
#pragma warning(push)
#pragma warning(disable : 4201)
	union {
		struct
		{
			float m_X;
			float m_Y;
		};
		float v[2];
	};
#pragma warning(pop)

public:
	vec2();
	vec2(float a_X, float a_Y);

	vec2& operator=(const vec2& rhs);

	vec2& operator+=(const vec2 &a_Rhs);
	vec2& operator-=(const vec2 &a_Rhs);
	vec2& operator*=(float a_Rhs);
	vec2& operator/=(float a_Rhs);

	float operator[](int a_Index) const;
	float& operator[](int a_Index);

	inline float dot(vec2 const& a_Rhs) const { return (m_X * a_Rhs.m_X + m_Y * a_Rhs.m_Y); };
	vec2& normalize();
	inline float length() const { return sqrtf((m_X*m_X) + (m_Y*m_Y)); };
};

vec2 operator+(const vec2 &a_Lhs, const vec2 &a_Rhs);
vec2 operator-(const vec2 &a_Lhs, const vec2 &a_Rhs);
vec2 operator*(const vec2 &a_Lhs, float a_Rhs);
vec2 operator/(const vec2 &a_Lhs, float a_Rhs);
bool operator==(const vec2 &a_Lhs, const vec2 &a_Rhs);
bool operator!=(const vec2 &a_Lhs, const vec2 &a_Rhs);

class vec3 {
public:
	//Prevent the warning 4201. This error means the structure containing m_X, m_Y and m_Z and the other structure containing r, g and b; they have no name.
#pragma warning(push)
#pragma warning(disable : 4201)
	union {
		struct
		{
			float m_X;
			float m_Y;
			float m_Z;
		};
		float v[3];
		struct
		{
			float r;
			float g;
			float b;

		};
	};
#pragma warning(pop)

public:
	vec3();
	vec3(float a_X, float a_Y, float a_Z);

	vec3& operator=(const vec3& rhs);

	vec3& operator+=(const vec3 &a_Rhs);
	vec3& operator-=(const vec3 &a_Rhs);
	vec3& operator*=(float a_Rhs);
	vec3& operator/=(float a_Rhs);

	float operator[](int a_Index) const;
	float& operator[](int a_Index);

	inline float dot(vec3 const& a_Rhs) const { return (m_X * a_Rhs.m_X + m_Y * a_Rhs.m_Y + m_Z * a_Rhs.m_Z); };
	inline vec3 cross(vec3 const& a_Rhs) const { return vec3((m_Y * a_Rhs.m_Z) - (m_Z * a_Rhs.m_Y), (m_Z * a_Rhs.m_X) - (m_X * a_Rhs.m_Z), (m_X * a_Rhs.m_Y) - (m_Y * a_Rhs.m_X)); };
	vec3& normalize();
	inline float length() const { return sqrtf((m_X*m_X) + (m_Y*m_Y) + (m_Z*m_Z)); };
	vec3 scalar(float scalar);
	vec3& colorClip();
};

vec3 operator+(const vec3 &a_Lhs, const vec3 &a_Rhs);
vec3 operator-(const vec3 &a_Lhs, const vec3 &a_Rhs);
vec3 operator*(const vec3 &a_Lhs, float a_Rhs);
vec3 operator/(const vec3 &a_Lhs, float a_Rhs);
bool operator==(const vec3 &a_Lhs, const vec3 &a_Rhs);
bool operator!=(const vec3 &a_Lhs, const vec3 &a_Rhs);
inline float dot(const vec3 &a_Lhs, const vec3 &a_Rhs) { return (a_Lhs.m_X * a_Rhs.m_X + a_Lhs.m_Y * a_Rhs.m_Y + a_Lhs.m_Z * a_Rhs.m_Z); }


class mat4
{
public:
#pragma warning(push)
#pragma warning(disable : 4201)
	union {
		struct
		{
			float m_00; float m_01; float m_02; float m_03;
			float m_10; float m_11; float m_12; float m_13;
			float m_20; float m_21; float m_22; float m_23;
			float m_30; float m_31; float m_32; float m_33;
		};
		float m[16];
	};
#pragma warning(pop)

public:
	mat4();
	mat4(vec3 a_Row0, float a_03,
		vec3 a_Row1, float a_13,
		vec3 a_Row2, float a_23,
		vec3 a_Row3, float a_33);
	mat4(float a_00, float a_01, float a_02, float a_03,
		float a_10, float a_11, float a_12, float a_13,
		float a_20, float a_21, float a_22, float a_23,
		float a_30, float a_31, float a_32, float a_33);

	mat4& operator=(const mat4& rhs);

	mat4& operator+=(const mat4 &a_Rhs);
	mat4& operator-=(const mat4 &a_Rhs);
	mat4& operator*=(const mat4 &a_Rhs);
	float operator[](int a_Index) const;
	float& operator[](int a_Index);

	float determinant() const;
	mat4& inverse();

	static mat4 identity();
	static mat4 rotateX(float a_Radians);
	static mat4 rotateY(float a_Radians);
	static mat4 rotateZ(float a_Radians);
	static mat4 translate(const vec3 &a_Translation);

	static mat4 lookat(const vec3 &a_Eye, const vec3 &a_Center, const vec3 &a_Up);
	static mat4 projection(float a_FovY, float a_AspectRatio, float a_Near, float a_Far);
};

mat4 operator+(const mat4 &a_Lhs, const mat4 &a_Rhs);
mat4 operator-(const mat4 &a_Lhs, const mat4 &a_Rhs);
mat4 operator*(const mat4 &a_Lhs, const mat4 &a_Rhs);
vec3 operator*(const mat4 &a_Lhs, const vec3 &a_Rhs);
