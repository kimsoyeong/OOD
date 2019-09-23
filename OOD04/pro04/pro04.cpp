#include "pch.h"
#include <string>
#include <iostream>

/*int main()
{
	std::string s;
	std::cout << "문자를 입력하세요(100자 이내)" << std::endl;
	std::cin >> s;
	std::cout << "입력된 문자는 " << s << "입니다." << std::endl;

	return 0;
}


//실습3
void increment(int x)
{
	++x;
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x);
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}

//실습4
void increment(int *x)
{
	++*x;
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(&x);
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}

//실습5
void increment(int &x)
{
	++x;
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x);
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}

//실습6
#include <iostream> 

int main()
{
	int y = 5;
	//int &x = 5; 
	int &x = y;
	std::cout << x << std::endl;
}*/

//실습7

void swap(int &first, int &second)
{
	int temp = first;
	first = second;
	second = temp;
}

int main()
{
	int a = 2, b = 3;
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	return 0;
}



