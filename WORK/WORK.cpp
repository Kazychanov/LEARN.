#include <iostream>
#include <string>
#include <optional>
using namespace std;

class MyClass;


class FriendClass
{
public:
	void takeMyClass(MyClass& etc);
private:
};


class MyClass
{
public:
	MyClass(int aa, int bb);
	friend void FriendClass::takeMyClass(MyClass& etc);
private:
	int a;
	int b;
};
MyClass::MyClass(int aa, int bb)
{
	this->a = aa;
	this->b = bb;
}



void FriendClass::takeMyClass(MyClass& classes)
{
	cout << "a: " << classes.a << endl;
	cout << "b: " << classes.b << endl;

}
int main() {
  setlocale(0, "");

	MyClass cs(5, 6);
	FriendClass fc;
	fc.takeMyClass(cs);
}

