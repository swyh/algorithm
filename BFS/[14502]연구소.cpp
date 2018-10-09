#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define BLANK	0
#define WALL	1
#define VIRUS	2

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int N, M;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

int bfs(vector<vector<int>> v, queue<pair<int, int>>& oq) {

	queue<pair<int, int>> q[2];
	bool flag = 0;

	q[flag] = oq;

	while (!q[flag].empty()) {
		while (!q[flag].empty()) {
			int fi = q[flag].front().first;
			int fj = q[flag].front().second;
			q[flag].pop();

			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				if (check(ki, kj) && v[ki][kj] == BLANK) {
					v[ki][kj] = VIRUS;
					q[!flag].push(make_pair(ki, kj));
				}
			}
		}
		flag = !flag;
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == BLANK)
				cnt++;
		}
	}

	return cnt;
}

int install(int n, int m, int cnt, vector<vector<int>>& v, queue<pair<int, int>>& q) {
	if (cnt == 2)
		return bfs(v, q);

	int value = 0;
	for (int i = n; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == BLANK) {
				v[i][j] = WALL;
				value = max(value, install(i, j, cnt + 1, v, q));
				v[i][j] = BLANK;
			}
		}
	}

	return value;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	queue <pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];

			if (v[i][j] == VIRUS)
				q.push(make_pair(i, j));
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == BLANK) {
				v[i][j] = WALL;
				answer = max(answer, install(i, j, 0, v, q));
				v[i][j] = BLANK;
			}
		}
	}

	cout << answer << endl;
	return 0;
}