#include <iostream>
#include "render.h"

using namespace std;

int main(){
	cout << "Hello World" << endl;
	testPrint("asdf");
	Render rend;
	Render rend2 = rend;
	std::cout << std::endl;
	return 0;
}
