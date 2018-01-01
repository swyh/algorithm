#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<char>> v;
vector<vector<bool>> visit;
vector<vector<int>> dist;
queue<pair<int, int>> q;
int N, M;
int cnt = 0;
int max_cnt = 0;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M || v[i][j] == 'W' || visit[i][j] == 1)
		return 0;
	else {
		visit[i][j] = 1;
		return 1;
	}
}

void BFS(int i, int j) {
	if (check(i, j)) {
		cnt++;
		q.push(make_pair(i, j));

		while (!q.empty()) {
			for (int k = 0; k < 4; k++) {
				int x = q.front().first + di[k];
				int y = q.front().second + dj[k];
				if (check(x, y)) {
					dist[x][y] = dist[q.front().first][q.front().second] + 1;
					q.push(make_pair(x, y));
				}
			}
			q.pop();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			max_cnt = max(max_cnt, dist[i][j]);
			visit[i][j] = 0;
			dist[i][j] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);

	cin >> N >> M;
	v.resize(N);
	visit.resize(N);
	dist.resize(N);
	for (int i = 0; i < N; i++) {
		v[i].resize(M);
		visit[i].resize(M);
		dist[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			BFS(i, j);
		}
	}

	cout << max_cnt << "\n";
}