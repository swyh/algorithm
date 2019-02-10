#include <iostream>
using namespace std;

int main() {
	long long s;
	cin >> s;

	long long i = 1;

	while (1) {
		long long result = (i * (i + 1)) / 2;
		if (result > s)
			break;
		i++;
	}

	cout << i - 1 << endl;

	return 0;
}