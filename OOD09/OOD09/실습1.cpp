#include "pch.h"
#include <iostream>

class Animal {
public:
	//...
protected:
	int age;
};
class Cat : public virtual Animal {/*.....*/ };
class Dog : public virtual Animal {/*....*/ };

class DogCat : public  Cat, public  Dog {
public:
	void setAge() {
		age = 10;
		Cat::age = 10;
	}
};
int main() {
	DogCat *dat = new DogCat();
	Animal *animal;
	animal = dat;
	animal = static_cast <Cat *>(dat);
	animal = (Cat *)dat;
}
