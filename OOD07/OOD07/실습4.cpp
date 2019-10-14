#include "pch.h"
#include <iostream>

class Parent {
	char *p;
public:
	Parent() {
		p = new char[10];
		std::cout << "Parent Constructor invocation" << std::endl;
	}
	virtual ~Parent() { //virtual 키워드를 붙인다.
		delete[] p;
		std::cout << "Parent Destructor invocation" << std::endl;
	}
};
class Child : public Parent {
	char *c;
public:
	Child() : Parent() {
		c = new char[10];
		std::cout << "Child Constructor invocation" << std::endl;
	}
	~Child() {
		delete[] c;
		std::cout << "Child Destructor invocation" << std::endl;
	}
};
int main() {
	std::cout << "--- Case1: Normal Child instantiation ---" << std::endl;
	Child *c = new Child();
	delete c;

	std::cout << "--- Case2: Parent pointer to Child ---" << std::endl;

	Parent *p = new Child();
	delete p;
	//new 연산자 사용시, 생성된 객체의 사용이 끝난 후,
	//해당 객체를 delete를 사용하여 제거해줘야 한다.

	getchar();
}
