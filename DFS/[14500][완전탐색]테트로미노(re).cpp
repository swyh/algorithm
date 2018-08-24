#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int max_val;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

void dfs(int px, int py, int x, int y, int cnt, int sum, vector<vector<int>>& v, vector<vector<bool>>& visit) {

	visit[x][y] = 1;

	for (int k = 0; k < 4; k++) {
		int i = x + di[k];
		int j = y + dj[k];

		if (0 <= i && 0 <= j && i < N && j < M && !visit[i][j]) {
			if (cnt == 3)
				max_val = max(max_val, sum + v[i][j]);
			else
				dfs(x, y, i, j, cnt + 1, sum + v[i][j], v, visit);
		}
	}

	if (px == -10)
		return;

	if (cnt == 3)
		dfs(-10, -10, px, py, cnt, sum, v, visit);

	visit[x][y] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	max_val = 0;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<bool>> visit(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, i, j, 1, v[i][j], v, visit);
		}
	}

	cout << max_val << endl;

	return 0;
}