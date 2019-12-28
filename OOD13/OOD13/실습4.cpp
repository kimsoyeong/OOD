#include "pch.h"
#include <iostream>

class RideStrategy {
public:
	virtual void ride() = 0;
};
class Bus : public RideStrategy {
public:
	void ride() {
		std::cout << "Ride bus!" << std::endl;
	}
};
class Taxi : public RideStrategy {
public:
	void ride() {
		std::cout << "Ride Taxi!" << std::endl;
	}
};
class Person {
public:
	Person(RideStrategy *ride) {
		rideStrategy = ride;
	}
	void run() {
		std::cout << "I run!" << std::endl;
	}
	void walk() {
		std::cout << "I walk!" << std::endl;
	}
	virtual void ride() { rideStrategy->ride(); }
	void setRideStratage(RideStrategy* ride) {
		rideStrategy = ride;
	}
protected:
	RideStrategy *rideStrategy;
};
class James : public Person {
public:
	James(RideStrategy *ride) : Person(ride) {};
	void ride() {
		std::cout << "James: " << std::endl;
		rideStrategy->ride();
	}
};
int main() {
	RideStrategy *rideBus = new Bus;
	RideStrategy *rideTaxi = new Taxi;
	Person *james = new James(rideBus);
	james->run();
	james->walk();
	james->ride();
	//Change the ride dynamically
	james->setRideStratage(rideTaxi);
	james->ride();
	return 0;
}
