#include <iostream>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	int i = 1, value = 0, min = 0x0fffffff, sum = 0;

	while (value <= 10000) {
		value = i * i;

		if (M <= value && value <= N) {
			if (sum == 0)
				min = value;
			sum += value;
		}
		i++;
	}

	if (sum == 0)
		cout << "-1" << endl;
	else
		cout << sum << endl << min << endl;

	return 0;
}