#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

int bfs(int i, int j, vector<vector<int>>& v) {
	vector<queue<pair<int, int>>> vq(2);
	vector<vector<bool>> visit(N, vector<bool>(N));
	vq[0].push(make_pair(i, j));
	visit[i][j] = 1;

	bool flag = 0;
	int K = 1;
	int result = 0;
	int home = 0;

	while (1) {
		int money = K * K + (K - 1) * (K - 1);

		while (!vq[flag].empty()) {
			int fi = vq[flag].front().first;
			int fj = vq[flag].front().second;
			vq[flag].pop();

			if (v[fi][fj] == 1)
				home++;

			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				if (check(ki, kj) && visit[ki][kj] == 0) {
					visit[ki][kj] = 1;
					vq[!flag].push(make_pair(ki, kj));
				}
			}
		}

		if ((home * M) - money >= 0)
			result = max(home, result);

		flag = !flag;
		K++;

		if (vq[flag].empty())
			break;

	}
	return result;
}

int foo() {
	int result = 0;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result = max(result, bfs(i, j, v));
		}
	}

	return result;
}

int main() {
	int T;
	cin >> T;


	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << foo() << "\n";
	}
	return 0;
}