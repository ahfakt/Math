#include "vec4.h"
#include <cmath>
#include "mat4.h"

namespace Math {

vec4::vec4(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W){}
vec4::vec4(vec3 const& XYZ, float W) : x(XYZ.x), y(XYZ.y), z(XYZ.z), w(W){}
vec4::vec4(vec4 const& V, vec4 const& U, float t) : vec4((U-V)*t + V){}

vec4& vec4::operator*=(vec4 const& U) { x*=U.x; y*=U.y; z*=U.z; w*=U.w; return *this; }
vec4& vec4::operator+=(vec4 const& U) { x+=U.x; y+=U.y; z+=U.z; w+=U.w; return *this; }
vec4& vec4::operator-=(vec4 const& U) { x-=U.x; y-=U.y; z-=U.z; w-=U.w; return *this; }

vec4& vec4::operator*=(float k)  { x*=k; y*=k; z*=k; w*=k; return *this; }
vec4& vec4::operator*=(double k) { return *this *= static_cast<float>(k); }
vec4& vec4::operator*=(mat4 const& N) { return *this = (*this)*N; }
vec4& vec4::operator/=(mat4 const& N) { return *this *= !N;}

vec4 operator-(vec4 const& V) { return {-V.x, -V.y, -V.z, -V.w}; }

vec4 operator*(vec4 const& V, vec4 const& U) { return {V.x*U.x, V.y*U.y, V.z*U.z, V.w*U.w}; }
vec4 operator+(vec4 const& V, vec4 const& U) { return {V.x+U.x, V.y+U.y, V.z+U.z, V.w+U.w}; }
vec4 operator-(vec4 const& V, vec4 const& U) { return {V.x-U.x, V.y-U.y, V.z-U.z, V.w-U.w}; }

vec4 operator*(vec4 const& V, float k)  { return {V.x*k, V.y*k, V.z*k, V.w*k}; }
vec4 operator*(vec4 const& V, double k) { return vec4(V.x*k, V.y*k, V.z*k, V.w*k); }
vec4 operator*(vec4 const& V, mat4 const& N) { return (N.X*V.x) + (N.Y*V.y) + (N.Z*V.z) + (N.W*V.w); }
vec4 operator/(vec4 const& V, mat4 const& N) { return V*!N; }

vec4 Unit(vec4 const& V) { double mag = Mag(V); return mag != 0.0 ? V*(1.0/mag) : V; }
vec4 Cross(vec4 const& Y, vec4 const& Z, vec4 const& W) {
	return vec4(
	Cross(vec3(Y.y, Y.z, Y.w), vec3(Z.y, Z.z, Z.w), vec3(W.y, W.z, W.w)),
	Cross(vec3(Y.x, Y.z, Y.w), vec3(W.x, W.z, W.w), vec3(Z.x, Z.z, Z.w)),
	Cross(vec3(Y.x, Y.y, Y.w), vec3(Z.x, Z.y, Z.w), vec3(W.x, W.y, W.w)),
	Cross(vec3(Y.x, Y.y, Y.z), vec3(W.x, W.y, W.z), vec3(Z.x, Z.y, Z.z)));
}

float Cross(vec4 const& X, vec4 const& Y, vec4 const& Z, vec4 const& W) { return Dot(X, Cross(Y, Z, W)); }
float Dot(vec4 const& V, vec4 const& U) { return V.x*U.x + V.y*U.y + V.z*U.z + V.w*U.w; }
double Mag(vec4 const& V) { return sqrt(Dot(V, V)); }

}//namespace Math
