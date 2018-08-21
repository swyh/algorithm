#include <iostream>
using namespace std;

int main() {
	long long X, Y, Z;
	cin >> X >> Y;

	Z = Y * 100 / X;

	int result = 0;
	int max = 1000000000;

	if (Z >= 99)
		result = -1;
	else {

		int s = 0;
		int e = max;
		int mid;

		while (s <= e) {
			mid = (s + e) / 2;

			int C = (Y + mid) * 100 / (X + mid);

			if (C <= Z)
				s = mid + 1;
			else
				e = mid - 1;
		}
		result = s;
	}

	cout << result << "\n";

	return 0;
}