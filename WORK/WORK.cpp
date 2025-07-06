#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;



int main() {
  SetConsoleOutputCP(1251);



  string path = "File.txt";

  fstream fs;
  fs.open(path, fstream::in | fstream::out | fstream::app);
  if (!fs.is_open()) {
    cout << "Ошибка открытия папки" << endl;
  }
  else {
    while (true) {
      cout << "Нажмите 1 для записи данных в файл" << endl;
      cout << "Нажмите 2 для чтения данных файлa" << endl;
      int value;
      cin >> value;
      fs.seekg(0);
      string str;
      switch (value)
      {
      case 1:
        SetConsoleCP(1251);
        cout << "Введите данные";
        cin >> str;
        fs << endl << str << endl;
        SetConsoleCP(866);
        break;
      case 2:
        while (!fs.eof()) {
          str = "";
          fs >> str;
          cout << str << endl;
        }
      }
    }
  }
  fs.close();
}

