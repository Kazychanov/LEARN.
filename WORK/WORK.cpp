#include <iostream>
#include <string>
using namespace std;

class A {
public:
	int i = 15;
	double y = 3.14;
};

int main() {
	setlocale(0, "");

	alignas(A)char buffer[sizeof(A) * 2];

	A* a1 = new (buffer) A;


}

