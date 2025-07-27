#pragma once
#include <iostream> 
#include <concepts>

using namespace std;

template<class T>
concept default_initializable = std::default_initializable<T>/* && requires*/;

template<class T>
struct ForwardList
{
private:
  struct Node {
    Node(T data, Node* ptr) : data(data), ptr(ptr) {}
    Node* ptr;
    T data;

    constexpr bool operator <(const Node& other) const {
      return this->data < other.data;
    }
    constexpr bool operator >(const Node& other) const {
      return this->data > other.data;
    }
  };

  Node* Head;
  Node* End;
  static const Node ForwardListEnd{ T(), nullptr }; // Инициализация статического элемента
  int Size;

public:
  ForwardList() noexcept : Head(&ForwardListEnd), End(&ForwardListEnd), Size(0) {}

  ~ForwardList() {
    clear();
  }

  constexpr void pushFront(T data) {
    if (!Size) {
      Head = End = new Node{ data, &ForwardListEnd };
    }
    else {
      Head = new Node(data, Head);
    }
    ++Size;
  }

  constexpr void pushBack(T data) {
    if (!Size) {
      Head = End = new Node(data, &ForwardListEnd);
    }
    else {
      End->ptr = new Node(data, &ForwardListEnd);
      End = End->ptr;
    }
    ++Size;
  }

  constexpr void popFront() {
    if (!Size) return;

    Node* tempNode = Head->ptr;
    delete Head;
    Head = tempNode;
    --Size;

    if (!Size) {
      End = &ForwardListEnd;
    }
  }

  constexpr void printNode() const {
    const Node* current = Head;
    int i = 1;
    while (current != &ForwardListEnd) {
      cout << "Номер: " << i << endl;
      cout << "Адрес:\t" << current << "\tЗначение:\t" << current->data << endl;
      ++i;
      current = current->ptr;
    }
    cout << "\nСписок окончен.\t" << "Элементов\t" << Size << endl;
    cout << "------------------------------------------------------" << endl;
  }

  constexpr void clear() {
    Node* current = Head;
    while (current != &ForwardListEnd) {
      Node* nextptr = current->ptr;
      delete current;
      current = nextptr;
    }
    Head = End = &ForwardListEnd;
    Size = 0;
  }

  constexpr bool insert(T data, int index) {
    if (index < 0 || index > Size)
      return false;

    if (index == 0) {
      pushFront(data);
      return true;
    }
    if (index == Size) {
      pushBack(data);
      return true;
    }

    Node* current = Head;
    for (int i = 0; i < index - 1; ++i) {
      current = current->ptr;
    }
    current->ptr = new Node(data, current->ptr);
    ++Size;
    return true;
  }

  constexpr bool remove(int index) {
    if (index < 0 || index >= Size)
      return false;

    if (index == 0) {
      popFront();
      return true;
    }

    Node* current = Head;
    for (int i = 0; i < index - 1; ++i) {
      current = current->ptr;
    }
    Node* toDelete = current->ptr;
    current->ptr = toDelete->ptr;

    if (toDelete == End) {
      End = current;
    }
    delete toDelete;
    --Size;
    return true;
  }

  struct Iterator1 {
    Iterator1(Node* start) : current(start) {}

    T& operator*() {
      return current->data;
    }

    const T& operator*() const {
      return current->data;
    }

    bool operator==(const Iterator1& other) const {
      return current == other.current;
    }

    bool operator!=(const Iterator1& other) const {
      return !(*this == other);
    }

    Iterator1& operator++() {
      if (current && current != &ForwardListEnd) {
        current = current->ptr;
      }
      return *this;
    }

    Iterator1 operator++(int) {
      Iterator1 temp = *this;
      ++(*this);
      return temp;
    }

  private:
    Node* current;
    friend struct ForwardList; // Дружественный доступ для ForwardList
  };

  Iterator1 begin() {
    return Iterator1(Head);
  }

  Iterator1 end() {
    return Iterator1(&ForwardListEnd);
  }

  // Удаляет элемент ПОСЛЕ указанного итератора
  bool remove_after(Iterator1 Iter) {
    if (Iter.current->ptr == &ForwardListEnd) {
      return false;
    }

    Node* toDelete = Iter.current->ptr;
    Iter.current->ptr = toDelete->ptr;

    if (toDelete == End) {
      End = Iter.current;
    }

    delete toDelete;
    --Size;
    return true;
  }

  // Вставляет элемент ПОСЛЕ указанного итератора
  bool insert_after(const T& data, Iterator1 Iter) {
    if (Iter == end()) {
      return false; // Невозможно вставить после end()
    }

    Node* newNode = new Node(data, Iter.current->ptr);
    Iter.current->ptr = newNode;

    if (Iter.current == End) {
      End = newNode;
    }

    ++Size;
    return true;
  }
};