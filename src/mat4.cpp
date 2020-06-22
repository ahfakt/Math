#include "mat4.h"
#include "mat3.h"

namespace Math {

mat4::mat4(float Ax, float Ay, float Az, float Aw, float Bx, float By, float Bz, float Bw, float Cx, float Cy, float Cz, float Cw, float Dx, float Dy, float Dz, float Dw) : X(Ax, Bx, Cx, Dx), Y(Ay, By, Cy, Dy), Z(Az, Bz, Cz, Dz), W(Aw, Bw, Cw, Dw){}
mat4::mat4(vec4 const& X, vec4 const& Y, vec4 const& Z, vec4 const& W) : X(X), Y(Y), Z(Z), W(W){}
mat4::mat4(mat3 const& M, vec3 const& W) : X(M.X), Y(M.Y), Z(M.Z), W(W, 1.f){}
mat4::mat4(mat3 const& M) : X(M.X), Y(M.Y), Z(M.Z), W(0.f, 0.f, 0.f, 1.f){}

mat4& mat4::operator*=(mat4 const& N) { X *= N; Y *= N; Z *= N; W *= N; return *this; }
mat4& mat4::operator/=(mat4 const& N) { return *this *= !N; }

mat4& mat4::operator*=(float k)  { X *= k; Y *= k; Z *= k; W *= k; return *this; }
mat4& mat4::operator*=(double k) { return *this *= static_cast<float>(k); }
mat4& mat4::operator*=(vec4 const& U) { X *= U.x; Y *= U.y; Z *= U.z; W *= U.w; return *this; }

mat4 operator!(mat4 const& M) {
	vec4 A(Cross(M.Y, M.Z, M.W));
	float invdet = 1.f/Dot(M.X, A);
	A *= invdet;
	vec4 B(Cross(M.X, M.W, M.Z)*invdet);
	vec4 C(Cross(M.X, M.Y, M.W)*invdet);
	vec4 D(Cross(M.X, M.Z, M.Y)*invdet);
	return {A.x, A.y, A.z, A.w, B.x, B.y, B.z, B.w, C.x, C.y, C.z, C.w, D.x, D.y, D.z, D.w};
}
mat4 operator~(mat4 const& M) { return {M.X.x, M.X.y, M.X.z, M.X.w, M.Y.x, M.Y.y, M.Y.z, M.Y.w, M.Z.x, M.Z.y, M.Z.z, M.Z.w, M.W.x, M.W.y, M.W.z, M.W.w}; }

mat4 operator*(mat4 const& M, mat4 const& N) { return {M.X*N, M.Y*N, M.Z*N, M.W*N}; }
mat4 operator/(mat4 const& M, mat4 const& N) { return M*!N; }

mat4 operator*(mat4 const& M, float k)  { return {M.X*k, M.Y*k, M.Z*k, M.W*k}; }
mat4 operator*(mat4 const& M, double k) { return {M.X*k, M.Y*k, M.Z*k, M.W*k}; }
mat4 operator*(mat4 const& M, vec4 const& U) { return {M.X*U.x, M.Y*U.y, M.Z*U.z, M.W*U.w}; }

float Det(mat4 const& M) { return Cross(M.X, M.Y, M.Z, M.W); }

}//namespace Math
