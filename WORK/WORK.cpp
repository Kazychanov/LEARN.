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

template<typename T1, typename T2>
struct MyStruct
{
	MyStruct(T1 value1, T2 value2) {
		this->value1 = value1;
		this->value2 = value2;
	}
	void  DataTypeSize() {
		cout << sizeof(value1) << endl;
		cout << sizeof(value2) << endl;
	}
private:
	T1 value1;
	T2 value2;
};

template<typename Т2>
struct MyStruct<string, Т2>
{
	MyStruct(string str1, Т2 str2) : value1(str1), value2(str2) {}
		string value1;
		Т2 value2;
	void DataTypeSize() {
		cout << sizeof(value1) << endl;
		cout << sizeof(value2) << endl;
	}
};

int main() {

	Point a(5, 3, 6);


	MyStruct<Point, int> ms1(a, 4);
	ms1.DataTypeSize();

	MyStruct<string, Point> ms2("1", a);
	ms2.DataTypeSize();
	return 0;
}

