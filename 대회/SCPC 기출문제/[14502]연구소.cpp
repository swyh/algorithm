#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> visit;
int N, M;

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool check(int i, int j) {
	if (i >= N || j >= M || i < 0 || j < 0)
		return 0;
	else
		return 1;
}

int BFS(int i, int j, vector<vector<int>>& visit) {
	bool ret = 1;
	if (v[i][j] == 0 && visit[i][j] == 0) {
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		visit[i][j] = 1;
		int temp = 1;

		while (!q.empty()) {
			for (int k = 0; k < 4; k++) {
				int x = q.front().first + di[k];
				int y = q.front().second + dj[k];

				if (check(x, y) && v[x][y] == 0 && visit[x][y] == 0) {
					q.push(make_pair(x, y));
					visit[x][y] = 1;
					temp++;
				}

				if (check(x, y) && v[x][y] == 2)
					ret = 0;
			}
			q.pop();
		}
		if (ret == 1)
			return temp;
		else
			return 0;
	}
	else
		return 0;
}

int func() {
	int temp = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp += BFS(i, j, visit);
		}
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;

	int cnt = 0;
	v.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < N; i++) {
		v[i].resize(M + 1);
		visit[i].resize(M + 1);
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] != 0)
				continue;
			v[i][j] = 1;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < M; l++) {
					if (v[k][l] != 0)
						continue;
					v[k][l] = 1;
					for (int q = 0; q < N; q++) {
						for (int w = 0; w < M; w++) {
							if (v[q][w] != 0)
								continue;
							v[q][w] = 1;

							cnt = max(cnt, func());
							v[q][w] = 0;
						}
					}
					v[k][l] = 0;
				}
			}
			v[i][j] = 0;
		}
	}
	cout << cnt << endl;
}