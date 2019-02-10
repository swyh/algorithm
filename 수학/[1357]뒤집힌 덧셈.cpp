#include <iostream>
#include <cmath>
using namespace std;

int reverse_int(int a) {

	int b = 0;
	int i = 0;

	while (a) {
		b += a % 10;
		a /= 10;
		b *= 10;
	}

	b /= 10;

	return b;
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << reverse_int((reverse_int(a) + reverse_int(b))) << endl;

	return 0;
}