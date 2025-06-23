#include <iostream>
#include <string>
#include <optional>
using namespace std;

	class Pixel {
	public:
		Pixel() {
			this->R = 0;
			this->G = 0;
			this->B = 0;
		}

		Pixel(int r, int g, int b) {
			this->R = r;
			this->G = g;
			this->B = b;
			count++;
		}
		string GetInfo() {
			return "#" + to_string(count) + " RGB:\t" + to_string(R) + "\t" + to_string(G) + "\t" + to_string(B);
		}
	private:
		static int count;
		int R, G, B;
	};

	int Pixel::count = 0;

int main() {
	setlocale(0, "");


  const int LENGHT = 5;

	Pixel static_arr[LENGHT];

	for (int i = 0; i < LENGHT; ++i) {
		static_arr[i] = Pixel(i, i + 1, i * 2);
		cout << static_arr[i].GetInfo() << endl;
	}

	int size;
	cout << "Введите количество: ";
	cin >> size;
	cout << endl;
	Pixel* dinamyc_arr = new Pixel[size];
	int r, g, b;
	for (int i = 0; i < size; i++) {
		cout << "Введите RGB: ";
		cin >> r >> g >> b;
		dinamyc_arr[i] = Pixel(r, g, b);
	}
	for (int i = 0; i < size; i++) {
		cout << dinamyc_arr[i].GetInfo() << endl;
	}
}

