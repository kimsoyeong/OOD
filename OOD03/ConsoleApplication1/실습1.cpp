#include "pch.h"
#include<iostream>

//�ǽ�1
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

//�ǽ�2
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

//�ǽ�3
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


//�ǽ� 4
#include <iostream> 

#define MAXSTACKSIZE 1000 // ������ �ִ� ũ��

class Stack {
	int top;

public:
	int a[MAXSTACKSIZE]; //����

	Stack() { top = -1; } //������ ����� �� �ʱ�ȭ
	bool push(int x);
	int pop();
};

bool Stack::push(int x)
{
	if (top >= (MAXSTACKSIZE - 1)) {
		std::cout << "����: ������ ���ƽ��ϴ�." << std::endl;
		return false;
	}
	else {
		a[++top] = x;
		std::cout << x << " �� ���ÿ� �����ϴ�." << std::endl;
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		std::cout << "����: ������ ������ϴ�." << std::endl;
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
	std::cout << s.pop() << " �� ���ÿ��� ���½��ϴ�." << std::endl;
	std::cout << s.pop() << " �� ���ÿ��� ���½��ϴ�." << std::endl;
	std::cout << s.pop() << " �� ���ÿ��� ���½��ϴ�." << std::endl;

	system("pause");

	return 0;
}
