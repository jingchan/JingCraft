#ifndef __jc_renderer
#define __jc_renderer

#include <string>

class World;

void testPrint(std::string str = "");
void testPrint2(std::string str = "");

class Render {
	std::string testString;
public:
	Render();
	Render(const Render &rhs);
	~Render();

	void RenderWorld(World&);
};

#endif
