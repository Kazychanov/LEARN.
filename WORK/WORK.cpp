#include <iostream>
#include <string>
using namespace std;

class Human {
public:
	Human(string name) {
		this->name = name;
		this->age = 0;
		this->wieght = 0;
	}
	Human(string name, int age) : Human(name){
		this->age = age;
	}
	Human(string name, int age, int weight) : Human(name, age) {
		this->wieght = weight;
	}
protected:
	string name;
	int age;
	int wieght;
};
int main() {
	setlocale(0, "");

	Human("Дмитрий")
}

