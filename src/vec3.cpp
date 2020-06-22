#include "vec3.h"
#include <cmath>
#include "quat.h"
#include "mat3.h"

namespace Math {

vec3::vec3(float X, float Y, float Z) : x(X), y(Y), z(Z){}
vec3::vec3(vec2 const& XY, float Z) : x(XY.x), y(XY.y), z(Z){}
vec3::vec3(vec4 const& XYZW) : x(XYZW.x), y(XYZW.y), z(XYZW.z){}
vec3::vec3(vec3 const& V, vec3 const& U, float t) : vec3((U-V)*t + V){}

vec3& vec3::operator*=(vec3 const& U) { x*=U.x; y*=U.y; z*=U.z; return *this; }
vec3& vec3::operator+=(vec3 const& U) { x+=U.x; y+=U.y; z+=U.z; return *this; }
vec3& vec3::operator-=(vec3 const& U) { x-=U.x; y-=U.y; z-=U.z; return *this; }

vec3& vec3::operator*=(float k)  { x*=k; y*=k; z*=k; return *this; }
vec3& vec3::operator*=(double k) { return *this *= static_cast<float>(k); }
vec3& vec3::operator*=(quat const& P) { return *this = (*this)*P; }
vec3& vec3::operator/=(quat const& P) { return *this *= !P;}
vec3& vec3::operator*=(mat3 const& N) { return *this = (*this)*N; }
vec3& vec3::operator/=(mat3 const& N) { return *this *= !N;}

vec3 operator-(vec3 const& V) { return {-V.x, -V.y, -V.z}; }

vec3 operator*(vec3 const& V, vec3 const& U) { return {V.x*U.x, V.y*U.y, V.z*U.z}; }
vec3 operator+(vec3 const& V, vec3 const& U) { return {V.x+U.x, V.y+U.y, V.z+U.z}; }
vec3 operator-(vec3 const& V, vec3 const& U) { return {V.x-U.x, V.y-U.y, V.z-U.z}; }

vec3 operator*(vec3 const& V, float k)  { return {V.x*k, V.y*k, V.z*k}; }
vec3 operator*(vec3 const& V, double k) { return vec3(V.x*k, V.y*k, V.z*k); }
vec3 operator*(vec3 const& V, quat const& P) { // q*v*(q^-1)
	vec4 t(V.x*P.w + V.z*P.y - V.y*P.z, V.y*P.w + V.x*P.z - V.z*P.x, V.z*P.w + V.y*P.x - V.x*P.y, V.x*P.x + V.y*P.y + V.z*P.z);
	return {t.x*P.w + t.w*P.x + t.z*P.y - t.y*P.z, t.y*P.w + t.w*P.y + t.x*P.z - t.z*P.x, t.z*P.w + t.w*P.z + t.y*P.x - t.x*P.y};
}
vec3 operator/(vec3 const& V, quat const& P) { return V*!P; }
vec3 operator*(vec3 const& V, mat3 const& N) { return (N.X*V.x) + (N.Y*V.y) + (N.Z*V.z); }
vec3 operator/(vec3 const& V, mat3 const& N) { return V*!N; }

vec3 R(vec3 const& V, vec3 const& U) { return P(V, U)*2.f - V; }
vec3 P(vec3 const& V, vec3 const& U) { return U*(Dot(V, U)/Dot(U, U)); }
vec3 N(vec3 const& V, vec3 const& U) { return V - P(V, U); }
vec3 Unit(vec3 const& V) { double mag = Mag(V); return mag != 0.0 ? V*(1.0/mag) : V; }
vec3 Cross(vec3 const& Y, vec3 const& Z) {
	return vec3(
	Cross(vec2(Y.y, Y.z), vec2(Z.y, Z.z)),
	Cross(vec2(Z.x, Z.z), vec2(Y.x, Y.z)),
	Cross(vec2(Y.x, Y.y), vec2(Z.x, Z.y)));
}

float Cross(vec3 const& X, vec3 const& Y, vec3 const& Z) { return Dot(X, Cross(Y, Z)); }
float Dot(vec3 const& V, vec3 const& U) { return V.x*U.x + V.y*U.y + V.z*U.z; }
double Mag(vec3 const& V) { return sqrt(Dot(V, V)); }

double Cos(vec3 const& V, vec3 const& U) {
	double R = Dot(V, U)/sqrt(Dot(U, U)*Dot(V, V));
	return R <= -1 ? -1 : (R >= 1 ? 1 : R);
}

}//namespace Math
