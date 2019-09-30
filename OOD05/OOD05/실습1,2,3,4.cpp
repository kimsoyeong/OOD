
#include "pch.h"
#include <iostream>
using namespace std;


//실습 1,2,3
int i;

class A
{
public:
	~A()
	{
		i = 10;
	}
};

//실습4
class Animal {
public:
	
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};

int& foo() //실습2-reference
{
	i = 3;
	{ //실습3-중괄호
		A ob;
	}
	return i;
}

int main()
{
	cout << foo() << endl;

	//실습 4번 답들
	//Animal a;
	Animal a(1);
	//Animal *a = new Animal(1);
	return 0;
}

