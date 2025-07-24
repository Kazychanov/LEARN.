#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
void DoWork() {
  for (size_t i = 0; i < 10; i++)
  {
    cout << this_thread::get_id() << "\tDoWork " << i << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
}


int main() {
  setlocale(0, "");
  cout << "START MAIN" << endl;

  thread th(DoWork);
  for (size_t i = 0; i < 10; i++)
  {
    cout << this_thread::get_id() << "\tmain " << i << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  
  th.join();
  return 0;
}
