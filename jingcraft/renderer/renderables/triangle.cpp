#include "../render_types.h"

Triangle::Triangle(const vec3 &a, const vec3 &b, const vec3 &c) {
	points[0] = a;
	points[1] = a;
	points[2] = a;
}

std::vector<Triangle *> getTriangles(){
	std::vector<Triangle *> v;
	v.push_back(this);
	return this;
}