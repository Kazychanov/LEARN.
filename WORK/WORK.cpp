#include <iostream>
#include <string>
#include <optional>
using namespace std;

class Cap {
public:
	string GeneratorColor() {
		return color;
	}
private:
	string color = "red";
};

class Human {
public:
	void think() {
		brain.think();
		inspectTheCap();
	}

	void inspectTheCap() {
		cout << "Моя кепка " << cap.GeneratorColor() << " цвета\n";
	}
private:
	class Brain {
	public:
		void think() {
			cout << "Я думаю" << endl;
		}
	private:
	};

	Brain brain;
	Cap cap;
};

int main() {
	setlocale(0, "");

	Human human;
	human.think();

}

