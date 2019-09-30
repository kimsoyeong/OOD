#include "pch.h"
#include <iostream>

//실습5
class Animal {
public:
	char* name;
	int age;

	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy_s(name, strlen(name_) + 1, name_);
	}

	Animal(Animal& a) { //복사 생성자
		age = a.age;

		name = new char[strlen(a.name) + 1];
		strcpy_s(name, strlen(a.name) + 1, a.name);
		//name = a.name; //a.name의 주소값을 name에 넣어주는 것
	}

	void changeName(const char* newName) {
		strcpy_s(name, strlen(newName) + 1, newName);
	}
	void printAnimal() {
		std::cout << "Name: " << name << " Age: "
			<< age << std::endl;
	}
};

void main() {

	Animal A(10, "Jenny"); //10살 Jenny 생성
	Animal B = A; // 10살 Jenny인 A를 B에게 복사
	A.age = 22;		//A의 나이를 22살로 바꿈
	A.changeName("Brown"); //A의 이름을 Brown으로 바꿈

	A.printAnimal();
	B.printAnimal();
}
