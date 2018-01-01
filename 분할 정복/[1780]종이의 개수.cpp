#include <iostream>
using namespace std;

int arr[2500][2500] = { 0 };
int num[3] = { 0 };
int n;

bool check(int x, int y, int m) {
	int start = arr[x][y];
	for (int i = x; i < x + m; i++) {
		for (int j = y; j < y + m; j++) {
			if (start != arr[i][j])
				return 0;
		}
	}
	return 1;
}

void solve(int x, int y, int m) {
	if (check(x, y, m)) {
		num[arr[x][y] + 1]++;
	}
	else {
		int a = m / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				solve(x + i*a, y + j*a, a);
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << num[i] << "\n";
}