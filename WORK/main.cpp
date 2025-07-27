#include <iostream>
#include <vector>
#include <algorithm>



int main() {
  setlocale(0, "");
  std::vector<int> v { 4,12,71,4,17,3,43,32,14,3245,7,243,512,354,665 };
  std::sort(v.begin(), v.end(), [](int a, int b) {return a < b; });

  for(auto el1 : v)
    std::cout << el1 << std::endl;
  
  return 0;
}
