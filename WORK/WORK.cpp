#include <iostream>
#include <string>
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
  setlocale(0, "");

  MyStruct ms2(10, 15, 9);
  MyStruct ms3;

  /* cout << ms2;*/

  string pathname = "ЯНЕГЕЙ";
  pathname += ".txt";

  fstream fs;
  fs.open(pathname, fstream::in | fstream::out | fstream::app);

  if (!fs.is_open())
    cout << "Ошибка открытия файла!" << endl;
  else {
    fs << ms2;
    fs.seekg(0);
    while (true) {
      fs >> ms3;
      if (fs.eof()) {
        break;
      }
      cout << ms3;
    }
  }

  return 0;
}

