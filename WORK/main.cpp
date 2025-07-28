#include <iostream>
#include <thread>

class MyClass
{
public:
  void Foo1() {
    for (size_t i = 0; i < 10; i++)
    {
      std::cout << "FOO1 " << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  }
  void Foo2(int a) {
    for (size_t i = 0; i < 10; i++)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      std::cout << "FOO2 " << a << std::endl;
    }
  }
};



int main() {
  setlocale(0, "");
  MyClass m;
  int a; std::cin >> a; 
  std::thread th(&MyClass::Foo2, m, a);
  std::thread th1([&m]() {m.Foo1(); });

  th.join();
  th1.join();
  return 0;
}
