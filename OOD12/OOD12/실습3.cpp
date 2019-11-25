#include "pch.h"
#include <iostream>

using namespace std;

bool funcA() {
	int c;
	std::cin >> c;
	if (c < 10) {//Let's assume this is exception
		//return false;
		throw out_of_range("Invalid Input!!"); //예외를 발생시킴
	}

	return true;
}
int main() {
	

	
	try {
		funcA();
	}
	catch (out_of_range& e) { //발생한 예외 처리
		cout << "Exception : "<< e.what() << endl; //발생한 예외를 출력
	}

	/*if (funcA())
	{
	}
	else {
		std::cout << "Exception : Invalid Input!!" << std::endl;
	}*/

	return 0;
}
