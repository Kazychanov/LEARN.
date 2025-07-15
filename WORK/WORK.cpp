#include <iostream>
// #include <ctime>
using namespace std;

template<class T>
struct ForwardList
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
  constexpr ForwardList() noexcept : Head(nullptr), End(nullptr), Size(0) {}

  constexpr ~ForwardList()
  {
    clear();
  }
    
  constexpr void pushFront(T data)
  {
    if (!Size)
    {
        Head = End = new Node(data);
    }
    else
    {
        Node* node = new Node(data);
        node->ptr = Head;
        Head = node;
    }
    ++Size;
  }
  constexpr void pushBack(T data) 
  {
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

  constexpr void printNode() const {
    const Node* current = Head;
    int i = 1;
    while (current) {
      cout << "Номер: " << i << endl;
      cout << "Адрес:\t" << current << "\tЗначение:\t" << current->data << endl;
      ++i;
      current = current->ptr;
    }
    cout << "\nСписок окончен.\t\t" << "\tЭлементов\t" << Size << endl;
  }

  constexpr void clear() {
    if (Head) {
      Node* current = Head;
      Node* nextptr = nullptr;
      while (current->ptr) {
        nextptr = current->ptr;
        delete current;
        current = nextptr;
      }
    }
    Head = nullptr;
    End = nullptr;
    Size = 0;
  }

  constexpr bool insert(T data, int index) 
  {
    if (index == 0)
    {
        pushFront(data);
        return true;
    }
    if (index < 0 || index > Size)
        return false;

    Node* node = Head;
    for (int i{0}; i != index - 1; ++i)
        node = node->ptr;
    Node* nodeNext = node->ptr;
    node->ptr = new Node(data);
    node->ptr->ptr = nodeNext;
    ++Size;
    return true;
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
        if (index == Size)
        End = current;
      }
      Size--;
    }
    cout << "недопустимый индекс для удаления" << endl;
  }

  Node* GetEnd() {
    return End;
  }

  T& operator [](int index) {
    Node* current = Head;
    int counter = 0;
    while (current) {
      if (counter == index)
        return current->data;
      current = current->ptr;
      counter++;
    }
    return *current;
  }
};


int main() {
  setlocale(0, "");
  srand(time(0));

  ForwardList<int> intlist;

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
  if (!intlist.insert(data, number - 1))
      std::cout << "Вставка не удалась\n";
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
