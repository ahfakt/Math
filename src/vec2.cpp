#include "vec2.h"
#include <cmath>
#include "vec3.h"
#include "quat.h"
#include "mat2.h"

namespace Math {

vec2::vec2(float X, float Y) : x(X), y(Y){}
vec2::vec2(vec3 const& XYZ) : x(XYZ.x), y(XYZ.y){}
vec2::vec2(vec2 const& V, vec2 const& U, float t) : vec2((U-V)*t + V){}

vec2& vec2::operator*=(vec2 const& U) { x*=U.x; y*=U.y; return *this; }
vec2& vec2::operator+=(vec2 const& U) { x+=U.x; y+=U.y; return *this; }
vec2& vec2::operator-=(vec2 const& U) { x-=U.x; y-=U.y; return *this; }

vec2& vec2::operator*=(float k)  { x*=k; y*=k; return *this; }
vec2& vec2::operator*=(double k) { return *this *= static_cast<float>(k); }
vec2& vec2::operator*=(quat const& P) { return *this = (*this)*P; }
vec2& vec2::operator/=(quat const& P) { return *this *= !P;}
vec2& vec2::operator*=(mat2 const& N) { return *this = (*this)*N; }
vec2& vec2::operator/=(mat2 const& N) { return *this *= !N;}

vec2 operator-(vec2 const& V) { return {-V.x, -V.y}; }

vec2 operator*(vec2 const& V, vec2 const& U) { return {V.x*U.x, V.y*U.y}; }
vec2 operator+(vec2 const& V, vec2 const& U) { return {V.x+U.x, V.y+U.y}; }
vec2 operator-(vec2 const& V, vec2 const& U) { return {V.x-U.x, V.y-U.y}; }

vec2 operator*(vec2 const& V, float k)  { return {V.x*k, V.y*k}; }
vec2 operator*(vec2 const& V, double k) { return vec2(V.x*k, V.y*k); }
vec2 operator*(vec2 const& V, quat const& P) { // q*v*(q^-1)
	vec4 t(V.x*P.w - V.y*P.z, V.y*P.w + V.x*P.z, V.y*P.x - V.x*P.y, V.x*P.x + V.y*P.y);
	return {t.x*P.w + t.w*P.x + t.z*P.y - t.y*P.z, t.y*P.w + t.w*P.y + t.x*P.z - t.z*P.x};
}
vec2 operator/(vec2 const& V, quat const& P) { return V*!P; }
vec2 operator*(vec2 const& V, mat2 const& N) { return (N.X*V.x) + (N.Y*V.y); }
vec2 operator/(vec2 const& V, mat2 const& N) { return V*!N; }

vec2 R(vec2 const& V, vec2 const& U) { return P(V, U)*2.f - V; }
vec2 P(vec2 const& V, vec2 const& U) { return U*(Dot(V, U)/Dot(U, U)); }
vec2 N(vec2 const& V, vec2 const& U) { return V - P(V, U); }
vec2 Unit(vec2 const& V) { double mag = Mag(V); return mag != 0.0 ? V*(1.0/mag) : V; }
vec2 Cross(vec2 const& Y) { return {Y.y, -Y.x}; }

float Cross(vec2 const& X, vec2 const& Y) { return Dot(X, Cross(Y)); }
float Dot(vec2 const& V, vec2 const& U) { return V.x*U.x + V.y*U.y; }
double Mag(vec2 const& V) { return sqrt(Dot(V, V)); }

double Cos(vec2 const& V, vec2 const& U) {
	double R = Dot(V, U)/sqrt(Dot(U, U)*Dot(V, V));
	return R <= -1 ? -1 : (R >= 1 ? 1 : R);
}

}//namespace Math
