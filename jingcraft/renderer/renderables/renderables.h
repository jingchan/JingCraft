#ifndef __jc_renderables
#define __jc_renderables

#include <string>
#include <vector>
#include <memory>

#include "render_types.h"

class IRenderable {
public:
	// std::vector<Triangles *> getTris();
	virtual std::vector<Triangle *> getTriangles() = 0;
};

class Triangle : public IRenderable {
	vec3 points[3];
public:
	Triangle(vec3, vec3, vec3);
	std::vector<Triangle *> getTriangles();
};

#endif
