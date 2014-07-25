#include "render.h"
#include <string>
#include <iostream>

using namespace std;

void testPrint(std::string str){
	std::cout << str << std::endl;
}

Render::Render(){
	cout << "Constructor" << endl;
}
Render::Render(const Render &rhs){
	cout << "Copy Constructor" << endl;
}
Render::~Render(){
	cout << "Destructor" << endl;
}