#include <string>
#include "world.h"
void testPrint(std::string str = "");

class Render {
	std::string testString;
public:
	Render();
	Render(const Render &rhs);
	~Render();

	RenderWorld(World&)
};