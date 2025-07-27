#include <iostream>
#include <thread>


using namespace std;

void DoWork(int a, int b) {
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout << "a+b " << a + b << endl;
}


int main() {
  setlocale(0, "");
  int a, b;
  cin >> a >> b;

  thread th(DoWork,a,b);
  for (size_t i = 0; true; i++)
  {
    cout << this_thread::get_id() << "\tmain " << i << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  th.join();
  return 0;
}
