#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	void Drive() {
		cout << "Я еду" << endl;
	}
private:
};

class Airplane {
public:
	void Fly() {
		cout << "Я лечу" << endl;
	}
private:
};

class FlyingCar : public Car, public Airplane{

};

int main() {
	setlocale(0, "");

	FlyingCar fc;
	
	Car* car = &fc;
}

