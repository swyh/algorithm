#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool check(int i, int j, const int N, const int M,
	const vector<vector<bool>> v, vector<vector<bool>>& visit) {
	if (i < 0 || j < 0 || i >= N || j >= M || v[i][j] == 0 || visit[i][j] == 1)
		return 0;
	else {
		visit[i][j] = 1;
		return 1;
	}
}

bool BFS(int i, int j, const int N, const int M, const vector<vector<bool>> v,
	vector<vector<bool>>& visit, queue<pair<int, int>>& q) {
	if (check(i, j, N, M, v, visit)) {
		q.push(make_pair(i, j));

		while (!q.empty()) {
			for (int k = 0; k < 4; k++) {
				int x = q.front().first + di[k];
				int y = q.front().second + dj[k];

				if (check(x, y, N, M, v, visit)) {
					q.push(make_pair(x, y));
				}
			}
			q.pop();
		}
		return 1;
	}
	else
		return 0;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		vector<vector<bool>> v;
		vector<vector<bool>> visit;
		queue<pair<int, int>> q;

		int M, N, K;
		int cnt = 0;
		cin >> M >> N >> K;

		v.resize(N);
		visit.resize(N);

		for (int i = 0; i < N; i++) {
			v[i].resize(M);
			visit[i].resize(M);
		}

		for (int i = 0; i < K; i++) {
			int m, n;
			cin >> m >> n;
			v[n][m] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (BFS(i, j, N, M, v, visit, q))
					cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}