#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int W, H;
int di[8] = { 1,-1,0,0,1,1,-1,-1 };
int dj[8] = { 0,0,1,-1,1,-1,1,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= H || j >= W)
		return 0;
	else
		return 1;
}

int dfs(int i, int j, vector<vector<char>>& v, vector<vector<bool>>& visit) {
	visit[i][j] = 1;

	int cnt = 1;
	for (int k = 0; k < 8; k++) {
		int ki = i + di[k];
		int kj = j + dj[k];
		if (check(ki, kj) && !visit[ki][kj] && v[ki][kj] == '.') {
			cnt += dfs(ki, kj, v, visit);
		}
	}

	return cnt;
}

int main() {
	cin >> W >> H;

	vector<vector<char>> v(H, vector<char>(W));
	vector<vector<bool>> visit(H, vector<bool>(W));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> v[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!visit[i][j] && v[i][j] == '.')
				answer = max(answer, dfs(i, j, v, visit));
		}
	}

	cout << answer << endl;

	return 0;
}