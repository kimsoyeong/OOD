#include "pch.h"
#include<iostream>

//실습1
class SetValue
{
public:
	int x, y;
};

int main()
{
	SetValue obj;
	
	obj.x = 33;
	obj.y = 44;

	std::cout << "X= " << obj.x << " , Y= " << obj.y << std::endl;

	system("pause");
	return 0;
}

//실습2
class SetValue
{
public:
	int x, y;

	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void show() {
		std::cout << "X= " << x << " , Y= " << y << std::endl;
	}

};

int main()
{
	SetValue obj;

	obj.setXY(33, 44);
	obj.show();

	system("pause");
	return 0;
}

//실습3
#include <stdio.h> 

void print(int var)
{
	printf("Integer number: %d \n", var);
}


void print(float var)
{
	printf("Float number: %f \n", var);
}


void print(int var1, float var2)
{
	printf("Integer number: %d \n", var1);
	printf(" and float number: %f", var2);
}

int main()
{
	int a = 7;
	float b = 9;

	print(a);
	print(b);
	print(a, b);

	return 0;
}


//실습 4
#include <iostream> 

#define MAXSTACKSIZE 1000 // 스택의 최대 크기

class Stack {
	int top;

public:
	int a[MAXSTACKSIZE]; //스택

	Stack() { top = -1; } //스택의 꼭대기 값 초기화
	bool push(int x);
	int pop();
};

bool Stack::push(int x)
{
	if (top >= (MAXSTACKSIZE - 1)) {
		std::cout << "오류: 스택이 넘쳤습니다." << std::endl;
		return false;
	}
	else {
		a[++top] = x;
		std::cout << x << " 이 스택에 들어갔습니다." << std::endl;
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		std::cout << "오류: 스택이 비었습니다." << std::endl;
		return 0;
	}
	else {
		int x=a[top--];
		return x;
	}
}


int main()
{
	class Stack s;
	s.push(7);
	s.push(88);
	s.push(999);
	std::cout << s.pop() << " 을 스택에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << " 을 스택에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << " 을 스택에서 꺼냈습니다." << std::endl;

	system("pause");

	return 0;
}
