#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int v[1000] = { 0 };
	int d;
	cin >> d;

	for (int i = 1; i < N; i++) {
		int k;
		cin >> k;

		v[k]++;
	}

	int cnt = 0;
	for (int i = 999; i > 0; i--) {

		if (d > i)
			break;

		while (d <= i && v[i] > 0) {
			v[i]--;
			if (i != 1)
				v[i - 1]++;
			d++;
			cnt++;
		}
	}

	cout << cnt << "\n";
}