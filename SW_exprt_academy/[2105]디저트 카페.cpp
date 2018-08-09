#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int di[4] = { -1,-1,1,1 };
int dj[4] = { -1,1,-1,1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

int move_idx(int& i, int& j, int cnt, int dist, bool kind[], vector<vector<int>>& v) {
	int result = 0;

	for (int k = 1; k <= cnt; k++) {

		i += di[dist];
		j += dj[dist];

		if (!check(i, j) || kind[v[i][j]])
			return 0;
		else {
			kind[v[i][j]] = 1;
			result++;
		}
	}

	return result;
}

int move(int i, int j, int l, int r, vector<vector<int>>& v) { // v[i][j]¿¡¼­ left, right

	bool kind[101] = { 0 };
	int result = 0;
	int temp = 0;
	int ki = i;
	int kj = j;

	temp = move_idx(ki, kj, r, 3, kind, v);
	result += temp;
	if (temp == 0)
		return 0;

	temp = move_idx(ki, kj, l, 2, kind, v);
	result += temp;
	if (temp == 0)
		return 0;

	temp = move_idx(ki, kj, r, 0, kind, v);
	result += temp;
	if (temp == 0)
		return 0;

	temp = move_idx(ki, kj, l, 1, kind, v);
	result += temp;
	if (temp == 0)
		return 0;

	return result;
}

int foo(int i, int j, vector<vector<int>>& v) {
	int result = 0;
	for (int r = 1; r <= N; r++) {
		for (int l = 1; l <= N; l++) {
			int temp = move(i, j, l, r, v);
			result = max(result, temp);
		}
	}
	return result;
}

int solve() {
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result = max(result, foo(i, j, v));
		}
	}

	if (result == 0)
		result = -1;
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