#ifndef __jc_renderer
#define __jc_renderer

#include <string>
#include <vector>
#include <memory>

#include "render_types.h"

#include "glm/glm.hpp"

class World;

void testPrint(std::string str = "");
void testPrint2(std::string str = "");

class Renderer {
	std::string testString;
public:
	Renderer();
	Renderer(const Renderer &rhs);
	~Renderer();

	// Renders a static state
	void RenderWorld(World&);

};

class RenderState {
	std::vector<std::shared_ptr<vec3> > data;
	


};

#endif
