#include <iostream>
using namespace std;

bool arr[101][101] = { 0 };

bool check(int i, int j) {
	if (i > 100 || j > 100 || i < 0 || j < 0 || arr[i][j] == 0)
		return 0;
	else
		return 1;
}

int main() {
	int n, cnt = 0;
	cin >> n;


	for (int t = 0; t < n; t++) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] == 0) {
				int temp = 0;
				temp += check(i, j + 1);
				temp += check(i, j - 1);
				temp += check(i + 1, j);
				temp += check(i - 1, j);
				if (temp >= 1) cnt += temp;
			}
		}
	}


	cout << cnt << endl;

}