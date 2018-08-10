#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

int cal(int i, int val, int m, vector<int>& v) {
	if (m + v[i] > C)
		return val;

	m += v[i];
	val += v[i] * v[i];

	int result = val;

	for (int j = i + 1; j < v.size(); j++) {
		result = max(result, cal(j, val, m, v));
	}

	return result;
}

int calculate(vector<int>& v) {
	// C 이하의 최대값 조합을 만들기
	int result = 0;

	for (int i = 0; i < v.size(); i++) {
		result = max(result, cal(i, 0, 0, v));
	}

	return result;
}

int work(int i, int j, int x, int y, vector<vector<int>>& v) {
	vector<vector<int>> visit(N, vector<int>(N));
	vector<int> num, num2;

	for (int k = 0; k < M; k++) {
		int ki = i;
		int kj = j + k;

		if (!check(ki, kj) || visit[ki][kj])
			return 0;

		num.push_back(v[ki][kj]);
		visit[ki][kj] = 1;
	}

	for (int k = 0; k < M; k++) {
		int ki = x;
		int kj = y + k;

		if (!check(ki, kj) || visit[ki][kj])
			return 0;

		num2.push_back(v[ki][kj]);
	}

	int result = 0;
	result += calculate(num);
	result += calculate(num2);

	return result;
}

int solve() {
	cin >> N >> M >> C;

	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int x = i; x < N; x++) {
				for (int y = 0; y < N; y++) {
					result = max(result, work(i, j, x, y, v));
				}
			}
		}
	}

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << solve() << "\n";
	}
	return 0;
}