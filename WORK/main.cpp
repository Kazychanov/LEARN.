#include <iostream>
#include <thread>

struct Functor
{
  void operator()(const int a) {
    if (a % 2 == 0) {
      SumEvenNum += a;
      ++CountEvenNum;
    }
  }
  int GetSumEvenNum() { return SumEvenNum; };
  int GetCountEvenNum() { return CountEvenNum; };
private:
  int SumEvenNum = 0, CountEvenNum = 0;
};


int main() {
  setlocale(0, "");
  int arr[]{ 4,12,71,4,17,3,43,32,14,3245,7,243,512,354,665 };
  Functor f;
  for (auto el1 : arr)
    f(el1);
  std::cout << "Сумма чётных чисел " << f.GetSumEvenNum() << "\tКоличество чётных чисел " << f.GetCountEvenNum() << std::endl;
  return 0;
}
