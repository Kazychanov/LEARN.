#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	Car()
	{
		cout << "Вызвался конструктор класса Car" << endl;
	}
	~Car() {
		cout << "Вызвался деструктор класса Car" << endl;
	}
	void Drive() {
		cout << "Я еду" << endl;
	}
private:
};

class Airplane {
public:
	Airplane()
	{
		cout << "Вызвался конструктор класса Airplane" << endl;
	}
	~Airplane()
	{
		cout << "Вызвался деструктор класса Airplane" << endl;
	}
	void Fly() {
		cout << "Я лечу" << endl;
	}
private:
};

class FlyingCar : public Car, public Airplane {
	public:
	FlyingCar()
	{
		cout << "Вызвался конструктор класса FlyingCar" << endl;
	}
	~FlyingCar()
	{
		cout << "Вызвался деcтруктор класса FlyingCar" << endl;
	}
};

int main() {
	setlocale(0, "");

	FlyingCar fc;

}