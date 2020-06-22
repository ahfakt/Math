#ifndef MATH_VEC2_H
#define MATH_VEC2_H

namespace Math {

union vec3;
union quat;
struct mat2;

struct vec2 {
	float x,y;

	vec2(float X = 0, float Y = 0);
	vec2(vec3 const& XYZ);
	vec2(vec2 const& V, vec2 const& U, float t);

	vec2& operator*=(vec2 const&);
	vec2& operator+=(vec2 const&);
	vec2& operator-=(vec2 const&);

	vec2& operator*=(float);
	vec2& operator*=(double);
	vec2& operator*=(quat const&);
	vec2& operator/=(quat const&);
	vec2& operator*=(mat2 const&);
	vec2& operator/=(mat2 const&);
};//struct vec2

vec2 operator-(vec2 const&);

vec2 operator*(vec2 const&, vec2 const&);
vec2 operator+(vec2 const&, vec2 const&);
vec2 operator-(vec2 const&, vec2 const&);

vec2 operator*(vec2 const&, float);
vec2 operator*(vec2 const&, double);
vec2 operator*(vec2 const&, quat const&);
vec2 operator/(vec2 const&, quat const&);
vec2 operator*(vec2 const&, mat2 const&);
vec2 operator/(vec2 const&, mat2 const&);

vec2 R(vec2 const& V, vec2 const& U);
vec2 P(vec2 const& V, vec2 const& U);
vec2 N(vec2 const& V, vec2 const& U);
vec2 Unit(vec2 const&);
vec2 Cross(vec2 const&);

float Cross(vec2 const&, vec2 const&);
float Dot(vec2 const&, vec2 const&);
double Mag(vec2 const&);

double Cos(vec2 const&, vec2 const&);

}//namespace Math

#endif //MATH_VEC2_H
