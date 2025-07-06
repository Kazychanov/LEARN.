#include <iostream>
#include <string>
using namespace std;

struct IBicycle
{
	void virtual TwistWheel() = 0;
	void virtual Ride() = 0;
};

struct SimpleBicycle : public IBicycle
{
	void TwistWheel() override {
		cout << " Метод TwistWheel\tкласса SimpleBicycle " << endl;
	}
	void Ride() override {
		cout << " Метод Ride\tкласса SimpleBicycle " << endl;
	}
};

struct Human
{
	void RideOn(IBicycle & bicycle) {
		cout << "Крутим руль." << endl;
		bicycle.TwistWheel();
		cout << "Поехали " << endl;
		bicycle.Ride();
	}
};

int main() {
	setlocale(0, "");
	Human h;
	SimpleBicycle sb;
	h.RideOn(sb);
}