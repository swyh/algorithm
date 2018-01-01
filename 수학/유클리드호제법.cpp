#include <iostream>
using namespace std;
//
//int gcd(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	else {
//		gcd(b, a%b);
//	}
//}

int gcd(int a, int b) {
	while (b) {
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}
int main() {
	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	cout << g << endl;
	cout << a * b / g << endl;
}