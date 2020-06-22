#ifndef MATH_MAT3X4_H
#define MATH_MAT3X4_H

#include "mat3.h"
#include "mat4.h"

namespace Math {

struct mat3x4 {
	mat3 S;
	vec3 T;
	mat3x4(float Ax = 1, float Ay = 0, float Az = 0, float Tx = 0, float Bx = 0, float By = 1, float Bz = 0, float Ty = 0, float Cx = 0, float Cy = 0, float Cz = 1, float Tz = 0);
	mat3x4(vec3 const& X, vec3 const& Y, vec3 const& Z, vec3 const& T);
	mat3x4(mat3 const& XYZ, vec3 const& T);
};//struct mat3x4

mat3x4 operator!(mat3x4 const&);

mat3x4 operator*(mat3x4 const&, mat3x4 const&);

mat4 operator*(mat3x4 const&, mat4 const&);

}//namespace Math

#endif //MATH_MAT3X4_H
