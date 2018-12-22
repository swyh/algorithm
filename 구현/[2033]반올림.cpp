#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, e = 0, p = 0;
	cin >> N;

	while (N > pow(10, e + 1)) {
		p = N / pow(10, e);
		p = p % 10;

		N = N / pow(10, e + 1);
		N = N * pow(10, e + 1);

		if (p >= 5) {
			N = N + pow(10, e + 1);
		}
		e++;
	}

	cout << N << endl;

	return 0;
}