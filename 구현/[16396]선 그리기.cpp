#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[10001] = { 0 };

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		for (int j = s; j < e; j++) {
			arr[j] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 10000; i++) {
		if (arr[i])
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}