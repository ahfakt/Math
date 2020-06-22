#ifndef MATH_VEC4_H
#define MATH_VEC4_H

#include "vec3.h"

namespace Math {

struct mat4;

union vec4 {
	vec3 v;
	struct { float x,y,z,w; };

	vec4(float X = 0, float Y = 0, float Z = 0, float W = 0);
	vec4(vec3 const& XYZ, float W = 0);
	vec4(vec4 const& V, vec4 const& U, float t);

	vec4& operator*=(vec4 const&);
	vec4& operator+=(vec4 const&);
	vec4& operator-=(vec4 const&);

	vec4& operator*=(float);
	vec4& operator*=(double);
	vec4& operator*=(mat4 const&);
	vec4& operator/=(mat4 const&);
};//union vec4

vec4 operator-(vec4 const&);

vec4 operator*(vec4 const&, vec4 const&);
vec4 operator+(vec4 const&, vec4 const&);
vec4 operator-(vec4 const&, vec4 const&);

vec4 operator*(vec4 const&, float);
vec4 operator*(vec4 const&, double);
vec4 operator*(vec4 const&, mat4 const&);
vec4 operator/(vec4 const&, mat4 const&);

vec4 Unit(vec4 const&);
vec4 Cross(vec4 const&, vec4 const&, vec4 const&);

float Cross(vec4 const&, vec4 const&, vec4 const&, vec4 const&);
float Dot(vec4 const&, vec4 const&);
double Mag(vec4 const&);

}//namespace Math

#endif //MATH_VEC4_H
