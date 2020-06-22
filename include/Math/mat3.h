#ifndef MATH_MAT3_H
#define MATH_MAT3_H

#include "vec3.h"

namespace Math {

union quat;

struct mat3 {
	vec3 X, Y, Z;
	mat3(float Ax = 1, float Ay = 0, float Az = 0, float Bx = 0, float By = 1, float Bz = 0, float Cx = 0, float Cy = 0, float Cz = 1);
	mat3(vec3 const& X, vec3 const& Y, vec3 const& Z);
	mat3(mat2 const& M, vec2 const& Z);
	mat3(mat2 const& M);
	mat3(quat const& Q);

	mat3& operator*=(mat3 const&);
	mat3& operator/=(mat3 const&);

	mat3& operator*=(float);
	mat3& operator*=(double);
	mat3& operator*=(vec3 const&);
};//struct mat3

mat3 operator!(mat3 const&);
mat3 operator~(mat3 const&);

mat3 operator*(mat3 const&, mat3 const&);
mat3 operator/(mat3 const&, mat3 const&);

mat3 operator*(mat3 const&, float);
mat3 operator*(mat3 const&, double);
mat3 operator*(mat3 const&, vec3 const&);

float Det(mat3 const&);

}//namespace Math

#endif //MATH_MAT3_H
