#include "pch.h"
#include <iostream>
#include <string> //visual studio 2019버전은 이거 없어도 됨.

class MyData {
	int number;
	std::string strNumber;	//여기서 string을 받아와서 사용하기 때문에 헤더를 추가
public:
	MyData(int data, std::string str) : number(data), strNumber(str) {}
	//Operator conversion
	operator int() { return number; }
	operator std::string() { return strNumber; }

	//Unary operator_overloading
	//이건 ms에서 지정한 약속이다; 후위_파라미터 int, 전위_비워야한다.
	int operator++(int) { //postfix operation (indicated by dummy 'int'):후위
		int temp = number;
		number++;
		return temp;
	}
	int operator++() { //prefix operation:전위
		return ++number;
	}

	friend std::ostream& operator<<(std::ostream&, MyData &); 
};

//friend : 클래스 밖에서 이 함수를 정의하는데, MyData클래스 내부의 strNumber을 사용하기 위해서 키워드 사용
// non-member operator<< function
std::ostream& operator<<(std::ostream& os, MyData & md) {
	return os << "This number is: " << md.strNumber << "\n";
	//원래 md.strNumber는 private(default는 private으로 취급)이므로 외부에서 참조 불가능
	//but friend를 사용함으로써 외부에서 클래스 내부의 member변수를 쓸 수 있게 해준다.
}

int main() {
	MyData mydata(1, "one");

	std::string strNum = mydata;
	int intNum = mydata;

	std::cout << strNum << std::endl; // one
	std::cout << intNum << std::endl; // 1
	std::cout << mydata++ << std::endl; // 1
	std::cout << ++mydata << std::endl; // 3
	std::cout << mydata;

}
