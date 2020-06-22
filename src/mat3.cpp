#include "mat3.h"
#include "mat2.h"
#include "quat.h"

namespace Math {

mat3::mat3(float Ax, float Ay, float Az, float Bx, float By, float Bz, float Cx, float Cy, float Cz) : X(Ax, Bx, Cx), Y(Ay, By, Cy), Z(Az, Bz, Cz){}
mat3::mat3(vec3 const& X, vec3 const& Y, vec3 const& Z) : X(X), Y(Y), Z(Z){}
mat3::mat3(mat2 const& M, vec2 const& Z) : X(M.X), Y(M.Y), Z(Z, 1.f){}
mat3::mat3(mat2 const& M) : X(M.X), Y(M.Y), Z(0.f, 0.f, 1.f){}
mat3::mat3(quat const& Q) : X(1-2*(Q.y*Q.y+Q.z*Q.z), 2*(Q.x*Q.y+Q.z*Q.w), 2*(Q.x*Q.z-Q.y*Q.w)), Y(2*(Q.x*Q.y-Q.z*Q.w), 1-2*(Q.x*Q.x+Q.z*Q.z), 2*(Q.y*Q.z+Q.x*Q.w)), Z(2*(Q.x*Q.z+Q.y*Q.w), 2*(Q.y*Q.z-Q.x*Q.w), 1-2*(Q.x*Q.x+Q.y*Q.y)){}

mat3& mat3::operator*=(mat3 const& N) { X *= N; Y *= N; Z *= N; return *this; }
mat3& mat3::operator/=(mat3 const& N) { return *this *= !N; }

mat3& mat3::operator*=(float k)  { X *= k; Y *= k; Z *= k; return *this; }
mat3& mat3::operator*=(double k) { return *this *= static_cast<float>(k); }
mat3& mat3::operator*=(vec3 const& U) { X *= U.x; Y *= U.y; Z *= U.z; return *this; }

mat3 operator!(mat3 const& M) {
	vec3 A(Cross(M.Y, M.Z));
	float invdet = 1.f/Dot(M.X, A);
	A *= invdet;
	vec3 B(Cross(M.Z, M.X)*invdet);
	vec3 C(Cross(M.X, M.Y)*invdet);
	return {A.x, A.y, A.z, B.x, B.y, B.z, C.x, C.y, C.z};
}
mat3 operator~(mat3 const& M) { return {M.X.x, M.X.y, M.X.z, M.Y.x, M.Y.y, M.Y.z, M.Z.x, M.Z.y, M.Z.z}; }

mat3 operator*(mat3 const& M, mat3 const& N) { return {M.X*N, M.Y*N, M.Z*N}; }
mat3 operator/(mat3 const& M, mat3 const& N) { return M*!N; }

mat3 operator*(mat3 const& M, float k)  { return {M.X*k, M.Y*k, M.Z*k}; }
mat3 operator*(mat3 const& M, double k) { return {M.X*k, M.Y*k, M.Z*k}; }
mat3 operator*(mat3 const& M, vec3 const& U) { return {M.X*U.x, M.Y*U.y, M.Z*U.z}; }

float Det(mat3 const& M) { return Cross(M.X, M.Y, M.Z); }

}//namespace Math
