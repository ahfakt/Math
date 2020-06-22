#include "quat.h"
#include <cmath>
#include "mat3.h"

namespace Math {

quat::quat(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) {}
quat::quat(vec4 const& U) : q(Unit(U)) {}
quat::quat(mat3 const& S) {
	double t = 1.0 + S.X.x + S.Y.y + S.Z.z;

	if(t > 0.00000001) {
		double s = std::sqrt(t)*2.0;
		q = Unit(vec4((S.Y.z-S.Z.y)/s, (S.Z.x-S.X.z)/s, (S.X.y-S.Y.x)/s, (float)0.25*s));
	}
	else if(S.X.x > S.Y.y && S.X.x > S.Z.z) {
		double s = sqrt(1.0 + S.X.x - S.Y.y - S.Z.z)*2.0;
		q = Unit(vec4((float)0.25*s, (S.X.y+S.Y.x)/s, (S.Z.x+S.X.z)/s, (S.Y.z-S.Z.y)/s));
	}
	else if(S.Y.y > S.Z.z) {
		double s = sqrt(1.0 + S.Y.y - S.X.x - S.Z.z)*2.0;
		q = Unit(vec4((S.X.y+S.Y.x)/s, (float)0.25*s, (S.Y.z+S.Z.y)/s, (S.Z.x-S.X.z)/s));
	}
	else {
		double s = sqrt(1.0 + S.Z.z - S.X.x - S.Y.y)*2.0;
		q = Unit(vec4((S.Z.x+S.X.z)/s, (S.Y.z+S.Z.y)/s, (float)0.25*s, (S.X.y-S.Y.x)/s));
	}
}
quat::quat(vec3 const& Axis, float Deg) : quat(Axis, M_PI/180.0 * Deg){}
quat::quat(vec3 const& Axis, double Rad) {
	Rad *= 0.5;
	v = Unit(Axis)*sin(Rad);
	w = cos(Rad);
}
quat::quat(vec3 const& From, vec3 const& To) {
	double css = (Cos(From, To) + 1.0)/2.0;
	v = Unit(Cross(From, To))*sqrt(1.0-css);
	w = sqrt(css);
}
quat::quat(quat const& Q, quat const& P, float t) : quat(!Q*P) {
	double rad = acos(w)*t;
	v = Unit(v)*sin(rad);
	w = cos(rad);
	*this = Q*(*this);
}
quat& quat::operator*=(quat const& P) { q = Unit(vec4((v*P.w) + (P.v*w) - Cross(v, P.v), w*P.w - Dot(v, P.v))); return *this; }
quat& quat::operator/=(quat const& P) { return *this *= !P; }

quat operator!(quat const& Q) { return {-Q.x, -Q.y, -Q.z, Q.w}; } // q^-1 = conj/(Mag^2)
quat operator-(quat const& Q) { return {-Q.x, -Q.y, -Q.z, -Q.w}; }

quat operator*(quat const& Q, quat const& P) { return vec4((Q.v*P.w) + (P.v*Q.w) - Cross(Q.v, P.v), Q.w*P.w - Dot(Q.v, P.v)); }
quat operator/(quat const& Q, quat const& P) { return Q*!P; }

}//namespace Math
