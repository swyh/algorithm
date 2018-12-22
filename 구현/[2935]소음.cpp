#include <iostream>
#include <string>
using namespace std;

void print_0(int n) {
	for (int i = 0; i < n; i++) {
		cout << 0;
	}
}

int main() {
	string A, B;
	char oper;
	cin >> A >> oper >> B;

	if (oper == '*') {
		cout << 1;
		print_0(A.length() + B.length() - 2);
	}
	else {
		if (A.length() == B.length()) {
			cout << 2;
			print_0(A.length() - 1);
		}
		else {
			int small = A.length() < B.length() ? A.length() : B.length();

			cout << 1;
			print_0(abs((int)(A.length() - B.length())) - 1);
			cout << 1;
			print_0(small - 1);
		}
	}

	cout << endl;
	return 0;
}