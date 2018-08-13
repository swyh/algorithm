#include <iostream>
#include <vector>
using namespace std;

#define A	0
#define B	1
int D, W, K;	// 두께, 가로크기, 합격기준

bool pass(vector<vector<int>>& v) {
	for (int j = 0; j < W; j++) {
		int cnt = 1;
		for (int i = 1; i < D; i++) {
			if (v[i - 1][j] == v[i][j])
				cnt++;
			else
				cnt = 1;

			if (cnt >= K)
				break;
		}
		if (cnt < K)
			return 0;
	}
	return 1;
}

void set_color(bool color, vector<int>& v) {
	for (int i = 0; i < W; i++)
		v[i] = color;
}

bool test(bool color, int num, int m, vector<vector<int>>& v) {	// 성공 1, 실패 0 반환
	vector<int> ori = v[num];

	set_color(color, v[num]);

	if (m > 0) {
		for (int i = num + 1; i < D; i++) {
			if (test(A, i, m - 1, v) || test(B, i, m - 1, v)) {
				v[num] = ori;
				return 1;
			}
		}
		v[num] = ori;
		return 0;
	}
	else if (pass(v)) {
		v[num] = ori;
		return 1;
	}
	else {
		v[num] = ori;
		return 0;
	}
}

int solve() {
	cin >> D >> W >> K;

	vector<vector<int>> v(D, vector<int>(W));

	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cin >> v[i][j];
		}
	}

	if (pass(v))
		return 0;

	int m = 1;	// 약
	while (m < D) {
		for (int i = 0; i < D; i++) {
			if (test(A, i, m - 1, v) || test(B, i, m - 1, v))
				return m;
		}
		m++;
	}

	return m;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << solve() << "\n";
	}
}