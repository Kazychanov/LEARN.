#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
  setlocale(0, "");

  string pathname = "ЯНЕГЕЙ";
  pathname += ".txt";
  ofstream fout;
  fout.open(pathname, ofstream::app);

  if (fout.is_open())
  {
    fout << "ЯГАМИ ЛАЙТ" << endl;
  }
  else {
    cout << "Ошибка открытия" << endl;
  }
  fout.close();

  ifstream fin;
  fin.open(pathname);
  if (fin.is_open()) {

    //cout << "CHAR\t______________________" << endl;
    //char ch;
    //while (fin.get(ch)) {
    //  cout << ch;
    //}

    //// Сбрасываем файловый указатель в начало файла
    //fin.clear();
    //fin.seekg(0);


    cout << "\nSTR\t______________________" << endl; // Добавил символ новой строки для разделения вывода
    string str;
    while (getline(fin, str)) { // Исправленное условие цикла
      cout << str << endl;
    }
  }
  else
    cout << "Ошибка открытия" << endl;

  fin.close();
}

