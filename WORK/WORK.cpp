#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

void FOO(int value) {
	if (value < 0)
		throw exception("Число меньше 0");
	else if (value > 10)
		throw exception("Число больше 10");
	else
  cout << "Переменная " << value << endl;
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
	try
	{
		FOO(5);
	}
	catch (const exception & ex)
	{
		cout << ex.what() << endl;
	}


  return 0;
}

