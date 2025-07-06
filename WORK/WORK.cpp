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

int main() {
  setlocale(0, "");

  MyStruct ms2(10, 0, 0);

  string pathname = "ЯНЕГЕЙ";
  pathname += ".txt";
  ofstream fout;
  fout.open(pathname, ofstream::app);

  if (fout.is_open())
  {
    fout.write((char*)&ms2, sizeof(MyStruct));
  }
  else {
    cout << "Ошибка открытия" << endl;
  }
  fout.close();

  ifstream fin;
  fin.open(pathname);
  if (fin.is_open()) {
    MyStruct readPoint;

    while (fin.read((char*)&readPoint, sizeof(MyStruct))) {
      readPoint.Print();
    }
  }
  else
    cout << "Ошибка открытия" << endl;

  fin.close();
}

