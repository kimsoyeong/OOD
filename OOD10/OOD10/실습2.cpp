#include "pch.h"
#include <iostream>
#include <string>

/* ....(실습1)에서 구현된 template swap ....*/
template <typename T>
void swap(T& a, T&b) {
	T temp = a;
	a = b;
	b = temp;
}

/* ... (추가) template swap의 string type specialization ... */
template<>
void swap(std::string& a, std::string& b) {
	//type 선언 형태는 위의 함수와 동일하게 해줘야 specialization 가능
	std::string temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";

	swap<int>(a, b); //swap(a,b)도 가능
	swap<float>(c, d); //swap(c,d)도 가능

   //(추가) e, f의 swap이 가능하도록 swap template 호출
	swap<>(e, f);

	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;

	return 0;
}
