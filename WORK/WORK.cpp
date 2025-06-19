#include <iostream>
#include <string>
#include <optional>
#define DEBUG
using namespace std;



//class MyClass {
//  int size;
//  int* data;
//public:
//  MyClass(int Size) {
//    this->size = Size;
//    this->data =  new int[Size];
//
//    for (int i = 0; i < size; i++) {
//      data[i] = i;
//    }
//    cout << data << "\tВызвался Конструктор" << endl;
//  }
//  MyClass(const MyClass& other) {
//    this->size = other.size;
//    this->data = new int[other.size];
//    for (int i = 0; i < size; i++) {
//      this->data[i] = other.data[i];
//    }
//    cout << data << "\tВызвался конструктор копирования" << endl;
//  }
//
//  ~MyClass() {
//    cout << data << "\tВызвался Деструктор" << endl;  
//    delete[] data;
//  }
//};
//
//
//void foo() {
//  cout << "Начало выполнении функции" << endl;
//
//  cout << "Конец выполнении функции" << endl;
//
//}

//class Worker;
//
//class FriendTest {
//  int a = 5;
//public:
//  friend void ChangeX(Worker& value, FriendTest& test);
//};

class Worker {
  int age = 20;
  int type = 20;
  optional<string> description;
  string name;
  int* grades;
  int size;
public:
  Worker(int age1, int type1, optional<string> description1, string name1, int size1){
    cout << "Вызвался конструктор\t" << this << endl;
    this->age = age1;
    this->type = type1;
    this->description = description1;
    this->name = name1;
    this->size = size1;
    this->grades = new int[size];
    for (int i = 0; i < size1; i++) {
      this->grades[i] = i;
    }
  }

  Worker(const Worker &other) {
    this->size = other.size;
    this->grades = new int[size];
    for (int i = 0; i < size; i++) {
      this->grades[i] = other.grades[i];
    }
    cout << "Вызвался конструктор копирования" << endl;
  }

  Worker & operator = (const Worker &other) {
    cout << "Вызвался оператор равно\t" << this << endl;
    
    this->age = other.age;
    this->type = other.type;
    this->description = other.description;
    this->name = other.name;

    this->size = other.size;

    if (this->grades != nullptr) {
      delete[] this->grades;
    }

    this->grades = new int[size];
    for (int i = 0; i < size; i++) {
      this->grades[i] = other.grades[i];
    }

    return *this;
  }

  ~Worker() {
    cout << "Вызвался деструктор\t" << this << endl;
    delete[] grades;
  }

  void printInfo();

 /* friend void ChangeX(Worker& value, FriendTest& test);*/
};

void Worker::printInfo()
{
  cout << "_______________________________________" << endl;
  cout << "\t\t" << this << endl;
  cout << "Имя:\t\t" << name << endl;
  cout << "Возраст:\t" << age << endl;
  cout << "Тип:\t\t" << type << endl;
  if (description == nullopt)
    cout << "Описания\tнет" << endl;
  else
    cout << "Описание:\t" << description.value() << endl;
  cout << "Оценки:\t\t";
  for (int i = 0; i < size; i++) {
    cout << grades[i] << " ";
  }
  cout << endl;
  cout << "_______________________________________" << endl;
}

//void ChangeX(Worker& value, FriendTest& test) {
//  cout << "Введите возраст" << endl;
//  int agetest;
//  cin >> agetest;
//  test.a = 5;
//  value.age = agetest;
//}

//class Point {
//public:
//  int x;
//  int y;
//
//  Point(int xval, int yval) {
//    x = xval;
//    y = yval;
//  }
//  Point() {
//    x = 0;
//    y = 0;
//  }
//  void Print() {
//    cout << "x:\t" << x << " y:\t" << y << endl;
//  }
//
//  bool operator ==(const Point& other) const {
//    return (x == other.x) && (y == other.y);
//  }
//
//  Point(const Point& other) {
//    this->x = other.x;
//    this->y = other.y;
//    cout << "Вызвался конструктор копирования" << endl;
//  }
//  ~Point() {
//    cout << "Вызвался деконструктор" << endl;
//  }
//
//  Point & operator= (const Point& other) {
//    this->x = other.x;
//    this->y = other.y;
//    return *this;
//  }
//
//  Point operator+ (const Point& other) {
//    Point temp;
//    temp.x = this->x + other.x;
//    temp.y = this->y + other.y;
//    return temp;
//  }
//  Point & operator++() {
//    this->x += 1;
//    this->y += 1;
//
//    return *this;
//  }
//
//  Point& operator++(int value) {
//    Point temp(*this);
//    this->x ++;
//    this->y ++;
//
//    return temp;
//  }
//};

//class IndexTest {
//  int arr[5]{ 5,123,43,64,765 };
//
//public:
//  int& operator[](int index) {
//    return arr[index];
//  }
//  
//};



int main() {
  setlocale(0, "");



  Worker id1(21, 1, nullopt, "Николай Петрович", 3);
  id1.printInfo();
  //FriendTest friendtest;
  //ChangeX(id1, friendtest);
  //id1.printInfo();

  //IndexTest a;
  //cout << a[2] << endl;
  //a[2] = 100;
  //cout << a[2] << endl;

  //Point a(1, 1);
  //Point b(a);
  //++b;
  //b.Print();
  //b++;
  //b.Print();
  /*
  Point c = a;
  a.Print();
  b.Print();
  c.Print();
  Point d = a + b + c;
  d.Print();
  */


  //MyClass a(1);
  //MyClass b(a);
}

