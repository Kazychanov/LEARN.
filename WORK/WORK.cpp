#include <iostream>
#include <ctime>
using namespace std;

template<class T>
struct List
{
private:
  struct Node {
    Node(T data = T(), Node* ptr = nullptr) {
      this->data = data;
      this->ptr = ptr;
    }
    Node* ptr;
    T data;
  };
  Node* Head;
  Node* End;
  int Size;
public:
  List<T>() :Head(nullptr), End(nullptr), Size(0){}

  ~List<T>()
  {
    clear();
  }

  void pushBack(T data) {
    if (!Size)
    {
      Head = End = new Node(data);
    }
    else
    {
      End->ptr = new Node(data);
      End = End->ptr;
      End->ptr = nullptr;
    }
    ++Size;

  }

  void printNode() {
    Node* current = Head;
    int i = 1;
    while (current != nullptr) {
      cout << "Номер: " << i << endl;
      cout << "Адрес:\t" << current << "\tЗначение:\t" << current->data << endl;
      i++;
      current = current->ptr;
    }
    cout << "\nСписок окончен.\t\t" << "\tЭлементов\t" << Size << endl;
  }

  void clear() {
    if (Head != nullptr) {
      Node* current = Head;
      Node* nextptr = nullptr;
      while (current->ptr != nullptr) {
        nextptr = current->ptr;
        delete current;
        current = nextptr;
      }
    }
    Head = nullptr;
    Size = 0;
  }

  void insert(T data, int index) {
    if (index >= 0 && index <= Size) {
      if (!index) {
        Head = new Node(data, Head);
      }
      else {
        Node* current = Head;
        for (int i = 1; i < index; i++) {
          current = current->ptr;
        }
        current->ptr = new Node(data, current->ptr);
        if (index == Size) {
          End = current->ptr;
        }
      }
      Size++;
    }
    else {
      cout << "Недопустимый индекс для вставки." << endl;
    }
  }

  void remove(int index) {
    if (index > 0 && index <= Size) {
      if (index == 1) {
        Node* nextptr = Head->ptr;
        delete Head;
        Head = nextptr;
      }
      else {
        Node* current = Head;
        for (int i = 1; i < index; i++) {
          current = current->ptr;
        }
        delete current->ptr;
        current->ptr = nullptr;
        if (index = Size)
        End = current;
      }
      Size--;
    }
    cout << "недопустимый индекс для удаления" << endl;
  }

  Node* GetEnd() {
    return End;
  }

  T& operator [](const int index) {
    Node* current = Head;
    int counter = 0;
    while (current != nullptr) {
      if (counter == index)
        return current->data;
      current = current->ptr;
      counter++;
    }
  }
};


int main() {
  setlocale(0, "");
  srand(time(0));

  List<int> intlist;

  cout << "--------------------------------------------------------------------" << endl;
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.printNode();
  cout << "Последний узел:\t" << intlist.GetEnd() << endl;

  cout << "--------------------------------------------------------------------" << endl;

  int data, number;
  cout << "Введите число и номер, после которого хотите создать узел: ";
  cin >> data >> number;
  intlist.insert(data, number);
  intlist.printNode(); 
  cout << "Последний узел:\t" << intlist.GetEnd() << endl;

  int deletenum;
  cout << "Введите номер, который хотите удалить: ";
  cin >> deletenum;
  intlist.remove(deletenum);
  intlist.printNode();
  cout << "Последний узел:\t" << intlist.GetEnd() << endl;
 /* intlist.remove(number);
  cout << "--------------------------------------------------------------------" << endl;

  intlist.printNode();*/

  intlist.clear();
  //cout << "--------------------------------------------------------------------" << endl;
  //intlist.pushBack(rand() % 10);
  //intlist.pushBack(rand() % 10);
  //intlist.pushBack(rand() % 10);
  //intlist.pushBack(rand() % 10);


  //intlist.printNode();
  //cout << intlist[2];

  return 0;
}