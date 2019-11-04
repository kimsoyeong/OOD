#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

class AnyString {
	std::string anyString;

public:
	AnyString(const std::string& anyString) : anyString(anyString) {}
	std::string getAnyString() {
		return "Stored String :: " + anyString;
	}
	friend std::ofstream& operator<<(std::ofstream& o, AnyString& a);
};

std::ofstream& operator<<(std::ofstream& o, AnyString& a) {
	o << a.getAnyString();

	return o;
}


int main() {

	std::ofstream out("testOveroding.txt");

	AnyString a("Hello, this is operator overloading test!!!");
	/*std::string output = a.getAnyString();
	out << output << std::endl;*/
	out << a << std::endl;
	// out << a.getAnyString() << std::endl; //µµ °¡´É

	return 0;
}
