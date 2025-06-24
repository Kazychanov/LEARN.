#include <iostream>
#include <string>
using namespace std;

class A {
public:
	A()
	{
		cout << "Вызвался конструктор класса B" << endl;
		msg = "Пустое сообщение";
	}
	A(string msg)
	{
		this->msg = msg;
	}
	void PrintMsg() {
		cout << msg << endl;

	}
private:
	string msg;
};

class B : public A {
public:
	B():A("наше новое сообщение")
	{
		cout << "Вызвался конструктор класса B" << endl;
	}
private:
};


class C : public B {
	public:
	C() {
		cout << "Вызвался конструктор класса C" << endl;
	}
};

int main() {
	setlocale(0, "");
	B value;
	value.PrintMsg();
}

