#ifndef MATH_VEC3_H
#define MATH_VEC3_H

#include "vec2.h"

namespace Math {

union vec4;
union quat;
struct mat3;

union vec3 {
	vec2 v;
	struct { float x,y,z; };

	vec3(float X = 0, float Y = 0, float Z = 0);
	vec3(vec2 const& XY, float Z = 0);
	vec3(vec4 const& XYZW);
	vec3(vec3 const& V, vec3 const& U, float t);

	vec3& operator*=(vec3 const&);
	vec3& operator+=(vec3 const&);
	vec3& operator-=(vec3 const&);

	vec3& operator*=(float);
	vec3& operator*=(double);
	vec3& operator*=(quat const&);
	vec3& operator/=(quat const&);
	vec3& operator*=(mat3 const&);
	vec3& operator/=(mat3 const&);
};//union vec3

vec3 operator-(vec3 const&);

vec3 operator*(vec3 const&, vec3 const&);
vec3 operator+(vec3 const&, vec3 const&);
vec3 operator-(vec3 const&, vec3 const&);

vec3 operator*(vec3 const&, float);
vec3 operator*(vec3 const&, double);
vec3 operator*(vec3 const&, quat const&);
vec3 operator/(vec3 const&, quat const&);
vec3 operator*(vec3 const&, mat3 const&);
vec3 operator/(vec3 const&, mat3 const&);

vec3 R(vec3 const& V, vec3 const& U);
vec3 P(vec3 const& V, vec3 const& U);
vec3 N(vec3 const& V, vec3 const& U);
vec3 Unit(vec3 const&);
vec3 Cross(vec3 const&, vec3 const&);

float Cross(vec3 const&, vec3 const&, vec3 const&);
float Dot(vec3 const&, vec3 const&);
double Mag(vec3 const&);

double Cos(vec3 const&, vec3 const&);

}//namespace Math

#endif //MATH_VEC3_H
