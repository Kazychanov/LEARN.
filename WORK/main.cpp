#include <iostream>
#include <functional>
#include <vector>

using vectorFunc = std::vector<std::function<void(int)>>;

void FOO(int a) {
  if(a % 2 == 0)
  std::cout << "FOO " << a << std::endl;
}
void BAR(int a) {
  if (a > 50)
  std::cout << "BAR " << a << std::endl;
}
void vfFOO(vectorFunc& vf, std::vector<int>& v) {
  for (auto a : v) {
    for (auto f : vf) {
      f(a);
    }
  }
}

int main() {
  setlocale(0, "");

  std::vector<int> v{ 2,4,645,1324,4,54 };
  vectorFunc vf{ FOO, BAR };
  vfFOO(vf, v);
  void(*functptr)(int a);
  std::cout << "++++++++++++++++++++++++++" << std::endl;
  functptr = BAR;
  for(auto a : v)
    functptr(a);
  functptr = FOO;
  for (auto a : v)
    functptr(a);
  return 0;
}
