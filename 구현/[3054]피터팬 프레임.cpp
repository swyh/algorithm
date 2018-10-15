#include <iostream>
#include <string>
using namespace std;

void frame_1(int size) {
	int iter = 5 + (size - 1) * 4;
	for (int i = 0; i < iter; i++) {
		if ((i - 2) % 4 == 0) {
			if ((i % 12) % 10 == 0)
				cout << "*";
			else
				cout << "#";
		}
		else
			cout << ".";
	}
	cout << endl;
}

void frame_2(int size) {
	int iter = 5 + (size - 1) * 4;
	for (int i = 0; i < iter; i++) {
		if (i % 2 == 0)
			cout << ".";
		else {
			if ((i % 12) % 9 == 0 || (i % 12) % 11 == 0)
				cout << "*";
			else
				cout << "#";
		}
	}
	cout << endl;
}

void frame_3(int size, string s) {
	int iter = 5 + (size - 1) * 4;
	for (int i = 0; i < iter; i++) {
		if (i % 2 == 1)
			cout << ".";
		else {
			if ((i - 2) % 4 == 0)
				cout << s[(i - 2) / 4];
			else if ((i != 0 && !(i == iter - 1 && s.size() % 3 != 0)) &&
				((i % 12) % 8 == 0 || (i % 12) % 12 == 0))
				cout << "*";
			else
				cout << "#";
		}
	}
	cout << endl;
}

int main() {
	string s;
	cin >> s;

	frame_1(s.size());
	frame_2(s.size());
	frame_3(s.size(), s);
	frame_2(s.size());
	frame_1(s.size());

	return 0;
}
