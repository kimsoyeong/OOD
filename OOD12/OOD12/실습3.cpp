#include "pch.h"
#include <iostream>

using namespace std;

bool funcA() {
	int c;
	std::cin >> c;
	if (c < 10) {//Let's assume this is exception
		//return false;
		throw out_of_range("Invalid Input!!"); //���ܸ� �߻���Ŵ
	}

	return true;
}
int main() {
	

	
	try {
		funcA();
	}
	catch (out_of_range& e) { //�߻��� ���� ó��
		cout << "Exception : "<< e.what() << endl; //�߻��� ���ܸ� ���
	}

	/*if (funcA())
	{
	}
	else {
		std::cout << "Exception : Invalid Input!!" << std::endl;
	}*/

	return 0;
}
