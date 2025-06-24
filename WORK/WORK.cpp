#include <iostream>
#include <string>
using namespace std;

class Weapon {
public:
	virtual void Shoot() = 0;
};

class Gun :public Weapon {
public:
	void Shoot() override {
		cout << "BANG!" << endl;
	}
};

class SubmachineGun : public Gun{
public:
	void Shoot() override 
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};

class Bazooka : public Weapon {
public:
	void Shoot() override
	{
		cout << "BADUUM!" << endl;
	}
};

class Knife : public Weapon{
public:
	void Shoot() override
	{
		cout << "FHJIUTSG!" << endl;
	}
};

class Player {
public:
	void Shoot(Weapon * Weapon) {
		Weapon->Shoot();
	}
};

int main() {
	setlocale(0, "");
	Knife knife;

	Player player;
	player.Shoot(&knife);
}

