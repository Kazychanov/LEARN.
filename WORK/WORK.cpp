#include <iostream>
#include <Windows.h>
using namespace std;

namespace space1 {
	struct MyStruct
	{
		int a = 4;
	};
}

namespace space2
{
	struct MyStruct
	{
		enum DAY {
			MONDAY,
			TUESDAY,
			WEDNESDAY,
			THURSDAY,
			FRIDAY,
			SATURDAY,
			SUNDAY
		};

		int a = 5;
	};
}

int main() {
	space1::MyStruct ms1;
	space2::MyStruct::DAY today = space2::MyStruct::DAY::MONDAY;
	switch (today)
	{
	case 0:
		cout << "MONDAY " << endl;
		break;
	case 1:
		cout << "TUESDAY" << endl;
		break;
	case 2:
		cout << "WEDNESDAY " << endl;
		break;
	case 3:
		cout << "THURSDAY" << endl;
		break;
	case 4:
		cout << "FRIDAY" << endl;
		break;
	case 5:
		cout << "SATURDAY" << endl;
		break;
	case 6:
		cout << "SUNDAY" << endl;
		break;
	default:
		break;
	}

	return 0;
}

