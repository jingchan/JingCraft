#include "render.h"
#include <string>
#include <iostream>

using namespace std;

void testPrint(std::string str){
	std::cout << str << std::endl;
}

Renderer::Renderer(){
	cout << "Constructor" << endl;
}
Renderer::Renderer(const Renderer &rhs){
	cout << "Copy Constructor" << endl;
}
Renderer::~Renderer(){
	cout << "Destructor" << endl;
}