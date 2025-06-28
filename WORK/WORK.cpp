#include <iostream>
#include <string>
using namespace std;

class A {
public:
	int i = 15;
	A() {
		cout << "Вызван конструктор A" << endl;
	}
};


void* operator new(size_t n) noexcept(false){
	if (n == 0) {
		n == 1;
	}
	while (true) {
		void* p = malloc(n);
		if (p) {
			cout << "Выделено " << n << " байт." << endl;
			return p;
		}
		new_handler nw = get_new_handler();
		if (!nw) {
			throw bad_alloc();
		}
		(*nw)();
	}
}

void operator delete(void* ptr, size_t size) {
	cout << "Очищено " << size << " байт" << endl;
	free(ptr);
}

int main() {
	setlocale(0, "");

	A *a = new A;
	delete a;
}

