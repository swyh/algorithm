#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int i3 = i / 100;
		int i2 = (i % 100) / 10;
		int i1 = i % 10;

		if (i3 == 0)
			cnt++;
		else if (i3 - i2 == i2 - i1)
			cnt++;
	}

	cout << cnt << endl;
}