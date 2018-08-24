#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	int p = 0;
	int result = 0;

	while (N - 9 * pow(10, p) > 0) {
		N = N - 9 * pow(10, p);
		result += (p + 1) * 9 * pow(10, p);
		p++;
	}

	result += (p + 1) * N;

	cout << result << endl;
	return 0;
}