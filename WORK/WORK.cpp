#include <iostream>
#include <string>
using namespace std;

class Gun {
public:
	virtual void Shoot() {
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

class Player {
public:
	void Shoot(Gun *gun) {
		gun->Shoot();
	}
};

int main() {
	setlocale(0, "");
	Gun gun;
	SubmachineGun machineGun;

	Player player;
	player.Shoot(&machineGun);
}

