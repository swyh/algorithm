#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {		// L번
	string A, B;	//이진수
	cin >> A >> B;

	unsigned long long a = 0, b = 0;	// 십진수
	for (int i = 0; i < A.length(); i++) {
		if (A[i] ==  '1')
			a += pow(2, A.length() - i - 1);
	}
	for (int i = 0; i < B.length(); i++) {
		if (B[i] == '1')
			b += pow(2, B.length() - i - 1);
	}

	unsigned long long c = a*b;
	vector<bool> C;
	unsigned long long temp = c;

	while (temp > 0) {
		unsigned long long result = temp % 2;
		temp = temp / 2;
		
		if (result == 1)
			C.push_back(1);
		else
			C.push_back(0);
	}

	for (int i = C.size()-1; i >= 0; i--) {
		cout << C[i];
	}
	cout << endl;

	return 0;
}