#include <iostream>
#include <string>
using namespace std;


class A {
public :
	A() {
		cout << "Выделена динамическая память под класс А" << endl;
	}
	virtual ~A() {
		cout << "Очищена динамическая память под класс А" << endl;
	}
};

class B :public A{
public:
	B() {
		cout << "Выделена динамическая память под класс B" << endl;
	}
	~B() override{
		cout << "Очищена динамическая память под класс B" << endl;
	}
};

int main() {
	setlocale(0, "");

	A* bptr = new B;
	delete bptr;
}

