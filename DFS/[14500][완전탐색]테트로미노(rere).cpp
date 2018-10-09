#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

int dfs(int cnt, int i, int j,
	vector<vector<int>>& v, vector<vector<bool>>& visit) {

	if (cnt == 5)
		return 0;

	visit[i][j] = 1;

	int max_val = 0;

	for (int k = 0; k < 4; k++) {
		int ki = i + di[k];
		int kj = j + dj[k];

		if (check(ki, kj) && !visit[ki][kj])
			max_val = max(max_val, dfs(cnt + 1, ki, kj, v, visit));
	}

	visit[i][j] = 0;

	return max_val + v[i][j];
}

int mount(int n, int i, int j, vector<vector<int>>& v) {

	int value = 0;
	for (int k = 0; k < 4; k++) {
		if (k == n)
			continue;

		int ki = i + di[k];
		int kj = j + dj[k];

		if (check(ki, kj))
			value += v[ki][kj];
	}

	return value + v[i][j];
}

int calculate(int i, int j,
	vector<vector<int>>& v, vector<vector<bool>>& visit) {
	int max_val = 0;

	max_val = max(max_val, dfs(1, i, j, v, visit));

	for (int k = 0; k < 4; k++)
		max_val = max(max_val, mount(k, i, j, v));

	return max_val;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<bool>> visit(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer = max(answer, calculate(i, j, v, visit));
		}
	}

	cout << answer << endl;

	return 0;
}