#include <iostream>
#include <Windows.h>
#include <memory>
using namespace std;

struct Point
{
	Point() {
		x = y = z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	int x, y, z;
};

ostream& operator <<(ostream& os, const Point& p) {
	os << p.x << " " << p.y << " " << p.z << endl;
	return os;
}

template<class T>
struct Sptr
{
	Sptr(T *ptr) {
		cout << "Вызвался конструктор умного указателя" << endl;

		this->ptr = ptr;
	}
	~Sptr()
	{
		cout << "Вызвался деструктор умного указателя" << endl;
		if (this->ptr == nullptr)
		delete ptr;
		this->ptr = nullptr;
	}
	T& operator *() {
		return *ptr;
	}
private:
	T *ptr;
};

int main() {
	setlocale(0, "");
	Point a(5,3,6);

	int size;
	cout << "Введите количество символов в массиве ";
	cin >> size;
	cout << endl;
	shared_ptr<int[]> ptr(new int[size]);
	for (int i = 0; i < size; i++) {
		ptr[i] = rand() % 10;
		cout << ptr[i] << "\t";
	}

	return 0;
}

