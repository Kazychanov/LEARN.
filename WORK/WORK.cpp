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

	Sptr<Point> sp(new Point(a));
	unique_ptr<Point> up1(new Point(a)); // Corrected: Use the constructor

	unique_ptr<Point> up2 = move(up1);
	up2.swap(up1); 
	up2.get(); //выдаёт сырой указатель
	up2.reset(); //освобождает и переменную и указатель
	up2.release(); //освобождает сам указатель

	shared_ptr<Point> sp1(new Point(a));
	shared_ptr<Point> sp2(sp1); //удаляется, когда остаётся последний поинтер

	return 0;
}

