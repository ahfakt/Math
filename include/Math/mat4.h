#ifndef MATH_MAT4_H
#define MATH_MAT4_H

#include "vec4.h"

namespace Math {

struct mat4 {
	vec4 X, Y, Z, W;
	mat4(float Ax = 1, float Ay = 0, float Az = 0, float Aw = 0, float Bx = 0, float By = 1, float Bz = 0, float Bw = 0, float Cx = 0, float Cy = 0, float Cz = 1, float Cw = 0, float Dx = 0, float Dy = 0, float Dz = 0, float Dw = 1);
	mat4(vec4 const& X, vec4 const& Y, vec4 const& Z, vec4 const& W);
	mat4(mat3 const& M, vec3 const& W);
	mat4(mat3 const& M);

	mat4& operator*=(mat4 const&);
	mat4& operator/=(mat4 const&);

	mat4& operator*=(float);
	mat4& operator*=(double);
	mat4& operator*=(vec4 const&);
};//struct mat4

mat4 operator!(mat4 const&);
mat4 operator~(mat4 const&);

mat4 operator*(mat4 const&, mat4 const&);
mat4 operator/(mat4 const&, mat4 const&);

mat4 operator*(mat4 const&, float);
mat4 operator*(mat4 const&, double);
mat4 operator*(mat4 const&, vec4 const&);

float Det(mat4 const&);

}//namespace Math

#endif //MATH_MAT4_H
