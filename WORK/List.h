#pragma once
#include <iostream> // for printNode
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
  struct Iterator1
  {
    Iterator1(Node* start) : current(start) {}

    T& operator*() {
      return current->data;
    }
    
    const T& operator*() const
    {
      return current->data;
    }

    bool operator == (const Iterator1& other) const {
      return current == other.current;
    }

    bool operator!=(const Iterator1& other) const {
      return !(*this == other);
    }

    Iterator1 operator++() {
      if (current && current->ptr)
        current = current->ptr;
      return current;
    }

    Iterator1 operator++(T) {
      Iterator1 temp = *this;
      ++(*this);
      return temp;
    }
  private:
    Node* current;
  };
  
  using const_iterator = const Iterator1;
  using iterator = Iterator1;

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
    if (index == Size)
    {
      pushBack(data);
      return true;
    }
    if (index < 0 || index > Size)
      return false;

    Node* current = Head;
    for (int i{ 0 }; i != index - 1; ++i)
      current = current->ptr;

    Node* nodeNext = current->ptr;
    current->ptr = new Node(data);
    current->ptr->ptr = nodeNext;
    ++Size;

    return true;
  }

  constexpr bool remove(int index) {
    if (index == 0) {
      Node* nextptr = Head->ptr;
      delete Head;
      Head = nextptr;
      return true;
    }
    if (index > Size || index < 0)
      return false;

    Node* current = Head;
    for (int i{ 0 }; i != index - 1; ++i)
      current = current->ptr;
    delete current->ptr;
    current->ptr = nullptr;
    if (index == Size)
      End = current;
    --Size;
    return true;
  }

  iterator begin() {
    return iterator{Head};
  }

  iterator end() {
    return iterator{End};
  }

  const_iterator cbegin(){
    return const_iterator{Head};
  }

  const_iterator cend(){
    return const_iterator{End};
  }

  const_iterator begin() const{
    return const_iterator{Head};
  }

  const_iterator end() const{
    return const_iterator{End};
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
