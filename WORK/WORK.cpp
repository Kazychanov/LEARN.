#include <iostream>
#include <ctime>
using namespace std;

template<class T>
struct List
{
private:
  template <class>
  struct Node {
    Node(T data = T(), Node* ptr = nullptr) {
      this->data = data;
      this->ptr = ptr;
    }
    Node* ptr;
    T data;
  };
  Node<T>* Head;
  int Size;
public:
  List<T>() {
    this->Size = 0;
    this->Head = nullptr;
  }

  ~List<T>()
  {
    clear();
  }

  void pushBack(T data) {
    if (Head == nullptr) {
      this->Head = new Node<T>(data);
    }
    else
    {
      Node<T>* current = Head;
      while (current->ptr != nullptr) {
        current = current->ptr;
      }
      current->ptr = new Node<T>(data);
    }
    this->Size++;

  }

  void printNode() {
    Node<T>* current = Head;
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
      Node<T>* current = Head;
      Node<T>* nextptr = nullptr;
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
      if (index == 0) {
        Head = new Node<T>(data, Head);
      }
      else {
        Node<T>* current = Head;
        for (int i = 1; i < index; i++) {
          current = current->ptr;
        }
        current->ptr = new Node<T>(data, current->ptr);
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
        Node<T>* nextptr = Head->ptr;
        delete Head;
        Head = nextptr;
      }
      else {
        Node<T>* current = Head;
        for (int i = 1; i < index; i++) {
          current = current->ptr;
        }
        Node<T>* nextptr = current->ptr;
        current->ptr = nextptr->ptr;
        delete nextptr;
      }
    }
    Size--;
    cout << "недопустимый индекс для удаления" << endl;
  }

  T& operator [](const int index) {
    Node<T>* current = Head;
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
  intlist.pushBack(1);
  intlist.pushBack(2);
  intlist.pushBack(3);
  intlist.pushBack(4);
  intlist.printNode();

  cout << "--------------------------------------------------------------------" << endl;

  int data, number;
  cout << "Введите число и номер, после которого хотите создать узел: ";
  cin >> data >> number;
  intlist.insert(data, number);
  intlist.printNode();
  intlist.remove(number);
  cout << "--------------------------------------------------------------------" << endl;

  intlist.printNode();

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