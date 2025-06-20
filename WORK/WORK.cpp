#include <iostream>
#include <string>
#include <optional>
using namespace std;

class Image {
public:

	void imageInfo() {
		for (int i = 0; i < LENGHT; i++) {
			cout << "#" <<  i << " " << pixels[i].PrintInfo() << endl;
		}
	}
private:
	class Pixel {
	public:
		Pixel(int r, int g, int b) {
			this->R = r;
			this->G = g;
			this->B = b;
		}
		string PrintInfo() {
			return "RGB:\t" + to_string(R) + "\t" + to_string(G) + "\t" + to_string(B);
		}
	private:
		int R, G, B;
	};
	static const int LENGHT = 5;
	Pixel pixels[LENGHT]
	{
	Pixel(0, 5, 4),
	Pixel(1, 3, 6),
	Pixel(5, 0, 7),
	Pixel(9, 2, 4),
	Pixel(3, 4, 1),

	};
};
int main() {
	setlocale(0, "");

	Image img;
	img.imageInfo();

}

