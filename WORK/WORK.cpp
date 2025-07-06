#include <iostream>
#include <string>
using namespace std;

struct Gun
{
	Gun() {
		cout << "пяу"
	}
	Gun(string pers){
		cout << "Паф Паф!" << endl;
		this->Person = pers;
	}

	string Person;
};

struct Pistol : virtual public Gun
{
	Pistol(string pers) /*: Gun(pers)*/ {
		cout << "Pistol: " << this->Person << endl;
	}
};

struct Rocket: virtual public Gun
{
	Rocket(string pers) /*: Gun(pers)*/ {
		cout << "Rocket: " << this->Person << endl;
	}
};

struct RocketPistol : public Rocket, public Pistol
{
	RocketPistol(string RocketPers, string PistolPers) : Rocket(RocketPers), Pistol(PistolPers) {
		cout << "Создан ракетный пистолет" << endl;
		cout << "Отец: " << RocketPers << endl;
		cout << "Мать: " << PistolPers << endl;

	}
};

int main() {
	setlocale(0, "");
	RocketPistol RK("Папа", "Мама");
}