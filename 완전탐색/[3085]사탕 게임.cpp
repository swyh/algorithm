#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<char>> v;

int cnt_h(int x, int y, char value) {
	int result_h = 0, temp = 0;

	for (int i = 0; i < n; i++) {	// 세로
		if (x == i || v[i][y] == value) {
			temp++;
			result_h = max(temp, result_h);
		}
		else
			temp = 0;
	}
	return result_h;
}

int cnt_v(int x, int y, char value) {
	int result_v = 0, temp = 0;

	for (int j = 0; j < n; j++) {	// 가로
		if (y == j || v[x][j] == value) {
			temp++;
			result_v = max(temp, result_v);
		}
		else
			temp = 0;
	}
	return result_v;
}


int main() {
	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; i++) {
		v[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (0 <= j - 1)
				result = max(result, cnt_h(i, j, v[i][j - 1]));	// 세로
			if (j + 1 < n)
				result = max(result, cnt_h(i, j, v[i][j + 1]));	// 세로

			if (0 <= i - 1)
				result = max(result, cnt_v(i, j, v[i - 1][j]));	// 가로
			if (i + 1 < n)
				result = max(result, cnt_v(i, j, v[i + 1][j]));	// 가로

			result = max(result, cnt_v(i, j, v[i][j]));	// 세로
			result = max(result, cnt_h(i, j, v[i][j]));	// 가로
		}
	}
	cout << result << endl;
}