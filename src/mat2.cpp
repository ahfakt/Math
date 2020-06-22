#include "mat2.h"

namespace Math {

mat2::mat2(float Ax, float Ay, float Bx, float By) : X(Ax, Bx), Y(Ay, By){}
mat2::mat2(vec2 const& X, vec2 const& Y) : X(X), Y(Y){}

mat2& mat2::operator*=(mat2 const& N) { X *= N; Y *= N; return *this; }
mat2& mat2::operator/=(mat2 const& N) { return *this *= !N; }

mat2& mat2::operator*=(float k)  { X *= k; Y *= k; return *this; }
mat2& mat2::operator*=(double k) { return *this *= static_cast<float>(k); }
mat2& mat2::operator*=(vec2 const& U) { X *= U.x; Y *= U.y; return *this; }

mat2 operator!(mat2 const& M) {
	vec2 A(Cross(M.Y));
	float invdet = 1.f/Dot(M.X, A);
	A *= invdet;
	vec2 B(Cross(-M.X)*invdet);
	return {A.x, A.y, B.x, B.y};
}
mat2 operator~(mat2 const& M) { return {M.X.x, M.X.y, M.Y.x, M.Y.y}; }

mat2 operator*(mat2 const& M, mat2 const& N) { return {M.X*N, M.Y*N}; }
mat2 operator/(mat2 const& M, mat2 const& N) { return M*!N; }

mat2 operator*(mat2 const& M, float k)  { return {M.X*k, M.Y*k}; }
mat2 operator*(mat2 const& M, double k) { return {M.X*k, M.Y*k}; }
mat2 operator*(mat2 const& M, vec2 const& U) { return {M.X*U.x, M.Y*U.y}; }

float Det(mat2 const& M) { return Cross(M.X, M.Y); }

}//namespace Math
