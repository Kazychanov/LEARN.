#include <iostream>
#include <string>
using namespace std;

class A {
public:
	string mes1 = "сообщение 1";
private:
	string mes2 = "сообщение 2";
protected:
	string mes3 = "сообщение 3";
};

class B : public A {
public:
	void GetInfo() {
		cout << mes1 << endl;
		cout << mes3 << endl;
	}
};

int main() {
	setlocale(0, "");
	B b;
	b.GetInfo();
}

