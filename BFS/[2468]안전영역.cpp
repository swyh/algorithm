#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

vector<vector<int>> v;
vector<vector<bool>> visit;
queue<pair<int, int>> q;
int N;
int cnt = 0;
int max_cnt = 0;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

void BFS(int i, int j, int w) {
	if (check(i, j) && visit[i][j] == 0 && v[i][j] > w) {
		cnt++;
		visit[i][j] = 1;
		q.push(make_pair(i, j));

		while (!q.empty()) {
			for (int k = 0; k < 4; k++) {
				int x = q.front().first + di[k];
				int y = q.front().second + dj[k];
				if (check(x, y) && visit[x][y] == 0 && v[x][y] > w) {
					q.push(make_pair(x, y));
					visit[x][y] = 1;
				}
			}
			q.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;

	v.resize(N);
	visit.resize(N);

	for (int i = 0; i < N; i++) {
		v[i].resize(N);
		visit[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			visit[i][j] = 0;
		}
	}

	for (int w = 0; w < 100; w++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				BFS(i, j, w);
			}
		}
		max_cnt = max(max_cnt, cnt);
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}
	}

	cout << max_cnt << "\n";
	return 0;
}
