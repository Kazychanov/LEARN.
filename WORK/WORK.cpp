#include <iostream>
#include <Windows.h>
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
		this->ptr = ptr;
	}
	~Sptr()
	{
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

	Point a(5, 3, 6);

	Sptr<Point> spa = new Point(a);
	cout << *spa << endl;

	cout << ((*spa).x + 1);
	return 0;
}

