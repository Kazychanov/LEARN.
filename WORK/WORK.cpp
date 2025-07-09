#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

class MyException : public exception {
public:
	MyException(const char* msg, int value) : exception(msg) {
		this->dataValue = value;
	}
  int GetDataValue()  {
		return dataValue;
	}
private:
	int dataValue = 0;
};

void FOO(int value) {
	if (value < 0)
		throw exception("Число меньше 0");
	else if (value > 10)
		throw MyException("Число больше 10", value);
	else
  cout << "Переменная " << value << endl;
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
	try
	{
		FOO(15);
	}
	catch ( MyException & ex) {
		cout << ex.what() << endl << ex.GetDataValue() << endl;
	}
	catch (const exception & ex)
	{
		cout << ex.what() << endl;
	}



  return 0;
}

