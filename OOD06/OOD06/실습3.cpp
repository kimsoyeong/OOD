#include "pch.h"
#include <iostream>
#include <string>

class Animal {
private:
	std::string name;

public:
	Animal() {};
	Animal(std::string name) : name(name) {};

	void showName() {
		std::cout << "Name is " << name << std::endl;
	}

	//operator+ �߰��ϼ���
	Animal operator+(const Animal &a) {
		Animal tmp;
		tmp.name = name + a.name;
		return tmp;
	};

};

int main() {

	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();

	Animal catDog = dog + cat; //������ �ռ�
	catDog.showName();

	dog.showName();

	getchar();

	return 0;
}
