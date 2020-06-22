#ifndef MATH_QUAT_H
#define MATH_QUAT_H

#include "vec4.h"

namespace Math {

struct mat3;

union quat {
	vec4 q;
	vec3 v;
	struct { float x,y,z,w; };

	quat(float X = 0, float Y = 0, float Z = 0, float W = 1);
	quat(vec4 const&);
	quat(mat3 const& S);
	quat(vec3 const& Axis, float Deg);
	quat(vec3 const& Axis, double Rad);
	quat(vec3 const& From, vec3 const& To);
	quat(quat const& Q, quat const& P, float t);

	quat& operator*=(quat const&);
	quat& operator/=(quat const&);
};//union quat

quat operator!(quat const&);
quat operator-(quat const&);

quat operator*(quat const&, quat const&);
quat operator/(quat const&, quat const&);

}//namespace Math

#endif //MATH_QUAT_H
