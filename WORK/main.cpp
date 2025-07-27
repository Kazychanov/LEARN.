#include <iostream>
#include <thread>



int Sum(int a, int b) {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return a + b;
}


int main() {
  setlocale(0, "");
  int a, b;
  std::cin >> a >> b;
  int result;

  std::thread th1([&result, &a, &b]() {result = Sum(a, b); });


  for (size_t i = 0; i <= 10; i++)
  {
    std::cout << std::this_thread::get_id() << "\tmain " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  th1.join();
  std::cout << "sum result = " << result << std::endl;
  return 0;
}
