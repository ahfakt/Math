#include "mat3x4.h"

namespace Math {

mat3x4::mat3x4(float Ax, float Ay, float Az, float Tx, float Bx, float By, float Bz, float Ty, float Cx, float Cy, float Cz, float Tz) : S(Ax, Bx, Cx, Ay, By, Cy, Az, Bz, Cz), T(Tx, Ty, Tz){}
mat3x4::mat3x4(vec3 const& X, vec3 const& Y, vec3 const& Z, vec3 const& T) : S(X, Y, Z), T(T) {}
mat3x4::mat3x4(mat3 const& XYZ, vec3 const& T) : S(XYZ), T(T) {}

mat3x4 operator!(mat3x4 const& M) {
	vec4 A(Cross(vec4(M.S.Y, 0), vec4(M.S.Z, 0), vec4(M.T, 1.0)));
	float invdet = 1.f/Dot(vec4(M.S.X, 0), A);
	A *= invdet;
	vec4 B(Cross(vec4(M.S.X, 0), vec4(M.T, 1.0), vec4(M.S.Z, 0))*invdet);
	vec4 C(Cross(vec4(M.S.X, 0), vec4(M.S.Y, 0), vec4(M.T, 1.0))*invdet);
	return {A.x, A.y, A.z, A.w, B.x, B.y, B.z, B.w, C.x, C.y, C.z, C.w};
}

mat3x4 operator*(mat3x4 const& M, mat3x4 const& N) { return {M.S*N.S, M.T*N.S + N.T}; }

mat4 operator*(mat3x4 const& M, mat4 const& N) { return {vec4(M.S.X)*N, vec4(M.S.Y)*N, vec4(M.S.Z)*N, vec4(M.T, 1.f)*N}; }

}//namespace Math
