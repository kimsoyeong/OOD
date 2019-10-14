#include <vector>
#include <string>
#include <iostream>

class Base1 {
public:
	Base1(int n): vector_(n,3){}
private:
	std::vector<char> vector_;
};

class Base2 {
public:
	Base2(int n): vector_(n,3){}
private:
	std::vector<char> vector_;
};

class Derived : public Base1, Base2 {
public:
	//Derived(const std::string & str): Base2(1024), Base1(512)
	//상속받은 부모 클래스 생성자가 먼저 호출된 후, 자식클래스의 생성자가 호출된다.
	Derived(const std::string & str) : Base1(512), Base2(1024) //상속받은 순서대로!!!
	{
		i = 0;
	}
private:
	std::string str_;
	int i = 0;
};

int main() {
	Derived drv("abc");
	return 0;
}