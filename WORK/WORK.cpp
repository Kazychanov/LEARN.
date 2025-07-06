#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	int n = 5;
	Car()
	{
		cout << "Вызвался конструктор класса Car" << endl;
	}
	~Car() {
		cout << "Вызвался деструктор класса Car" << endl;
	}
	int Use(int n) {
		this->n += n;
		cout << "\nЯ еду\n" << endl;
		return this->n;
	}
private:
};

class Airplane {
public:
	int m = 5;
	Airplane()
	{
		cout << "Вызвался конструктор класса Airplane" << endl;
	}
	~Airplane()
	{
		cout << "Вызвался деструктор класса Airplane" << endl;
	}
	void Use() {
		cout << "\nЯ лечу\n" << endl;
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

	Car* car_ptr = &fc;
	car_ptr->Use(10);
	cout << "\tn = " << car_ptr->n << endl;

	Airplane* airplane_ptr = &fc;
	airplane_ptr->Use();
	cout << "\tm = " << airplane_ptr->m << endl;

	cout << "\tn = " << car_ptr->n << endl;
}