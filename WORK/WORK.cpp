#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

struct MyStruct
{
  MyStruct() {
    x = y = z = 0;
  }
  MyStruct(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  void Print() {
    cout << "x: " << x << " y: " << y << " z: " << z << endl;
  }
  int x, y, z;
};

ostream& operator << (ostream& os, const MyStruct& point) {

  os << point.x << " " << point.y << " " << point.z << "\n";
  return os;
}

istream& operator >> (istream& is, MyStruct& point) {
  is >> point.x >> point.y >> point.z;
  return is;
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  string path = "test123.txt";

  fstream fs;
  fs.exceptions(fstream::badbit | fstream::failbit);
  
  try
  {
    cout << "открытие файла" << endl;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    cout << "файл открыт" << endl;
  }
  catch (const fstream::failure & ex)
  {
    cout << ex.what() << endl;
    cout << ex.code() << endl;
    cout << "ошибка открытия файла" << endl;
  }
  fs.close();
  return 0;
}

