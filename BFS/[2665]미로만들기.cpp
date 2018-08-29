#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

void bfs(int i, int j, vector<vector<int>>& v, vector<vector<int>>& visit) {
	queue<pair<int, int>> q[2];
	bool flag = 0;

	q[flag].push(make_pair(i, j));
	visit[i][j] = 0;

	while (!q[flag].empty()) {
		while (!q[flag].empty()) {
			int fi = q[flag].front().first;
			int fj = q[flag].front().second;
			q[flag].pop();

			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];
				int cost = 0;

				if (check(ki, kj) && v[ki][kj] == 0)
					cost++;

				if (check(ki, kj) && visit[ki][kj] == -1) {
					q[!flag].push(make_pair(ki, kj));
					visit[ki][kj] = visit[fi][fj] + cost;
				}
				else if (check(ki, kj) && visit[ki][kj] > visit[fi][fj] + cost) { // update
					q[!flag].push(make_pair(ki, kj));
					visit[ki][kj] = visit[fi][fj] + cost;
				}
			}
		}
		flag = !flag;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));
	vector<vector<int>> visit(N, vector<int>(N, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;

			v[i][j] = c - '0';
		}
	}

	bfs(0, 0, v, visit);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}

	cout << visit[N - 1][N - 1] << '\n';

	return 0;
}