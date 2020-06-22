#ifndef MATH_MAT2_H
#define MATH_MAT2_H

#include "vec2.h"

namespace Math {

struct mat2 {
	vec2 X, Y;
	mat2(float Ax = 1, float Ay = 0, float Bx = 0, float By = 1);
	mat2(vec2 const& X, vec2 const& Y);

	mat2& operator*=(mat2 const&);
	mat2& operator/=(mat2 const&);

	mat2& operator*=(float);
	mat2& operator*=(double);
	mat2& operator*=(vec2 const&);
};//struct mat2

mat2 operator!(mat2 const&);
mat2 operator~(mat2 const&);

mat2 operator*(mat2 const&, mat2 const&);
mat2 operator/(mat2 const&, mat2 const&);

mat2 operator*(mat2 const&, float);
mat2 operator*(mat2 const&, double);
mat2 operator*(mat2 const&, vec2 const&);

float Det(mat2 const&);

}//namespace Math

#endif //MATH_MAT2_H
