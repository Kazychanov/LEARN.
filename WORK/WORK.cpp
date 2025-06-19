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
	friend FriendClass;
public:
	MyClass(int aa, int bb);
private:
	static int count;
	int a;
	int b;
};
MyClass::MyClass(int aa, int bb)
{
	this->a = aa;
	this->b = bb;
	count++;
}
int MyClass::count = 0;


void FriendClass::takeMyClass(MyClass& classes)
{
	cout << "a: " << classes.a << endl;
	cout << "b: " << classes.b << endl;
	cout << "c: " << classes.count << endl;

}
int main() {
  setlocale(0, "");

	MyClass cs(5, 6);
	FriendClass fc;
	fc.takeMyClass(cs);

	cout << "___________________________" << endl;

	MyClass cs1(5, 6);
	fc.takeMyClass(cs1);
}

