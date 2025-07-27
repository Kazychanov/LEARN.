#include <iostream>


int main() {
  setlocale(0, "");
  int p = 1;
  int a = 5;
  auto f = [&p,&a](int a1) {p += a + a1; return true; };
  f(a);
  std::cout << p << std::endl;
  return 0;
}
