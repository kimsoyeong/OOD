#include "pch.h"
#include <iostream>
#include <string>

class Employee {
protected:
	std::string name;
	int age;

public:
	Employee(std::string name, int age) : name(name), age(age) {}

	virtual void showInfo() { std::cout << "Name:" << name << ", Age: " << age << std::endl; }
};

class Manager : public Employee { //Employee를 상속
	int managerBonus;
public:
	Manager(int managerBonus, std::string name, int age) : managerBonus(managerBonus), Employee(name, age) {}

	void showInfo() { std::cout << "Manager Name:" << name << ", Age: " << age << ", managerBonus:" << managerBonus << std::endl; }
};

class Intern : public Employee { //Employee를 상속
	std::string majorName;
public:
	Intern(std::string major, std::string name, int age) : majorName(major), Employee(name, age) {}

	void showInfo() { std::cout << "Intern Name:" << name << ", Age: " << age << ", Major:" << majorName << std::endl; }
};

class Janitor : public Employee {
	int salary;
public:
	Janitor(int salary, std::string name, int age) : salary(salary), Employee(name, age) {}

	void showInfo() { std::cout << "Janitor Name:" << name << ", Age: " << age << ", Salary:" << salary << std::endl; }
};

int main() {

	Employee** employlist = new Employee*[6];
	//upcasting_메모리의 효율을 얻을 수 있다.
	employlist[0] = new Manager(200, "James", 33);
	employlist[1] = new Manager(150, "Chulsoo", 50);

	employlist[2] = new Intern("security", "Minsu", 24);
	employlist[3] = new Intern("HCI", "Yong", 19);
	employlist[4] = new Janitor(100, "Black", 90);
	employlist[5] = new Janitor(200, "White", 100);


	employlist[0]->showInfo();
	employlist[1]->showInfo();

	employlist[2]->showInfo();
	employlist[3]->showInfo();

	employlist[4]->showInfo();
	employlist[5]->showInfo();

	getchar();
	return 0;
}