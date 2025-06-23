#include <iostream>
#include <string>
using namespace std;

class Human {
public:
	string name;
};

class Student : public Human {
	string group = "10A";
public:
	string GetGroup() {
		return group;
	}
};

class Professor : public Student {
public:
	string object;
};

int main() {
	setlocale(0, "");
	Professor pr;
	cout<< pr.GetGroup();
}

