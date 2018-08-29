#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define GROUND	0
#define WALL	1
#define WOLF	2
#define	SHEEP	3

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

int N, M;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

pair<int, int> bfs(int i, int j, vector<vector<int>>& v, vector<vector<bool>>& visit) {
	queue<pair<int, int>> q[2];
	bool flag = 0;
	pair<int, int> p;

	q[flag].push(make_pair(i, j));

	while (!q[flag].empty()) {
		while (!q[flag].empty()) {
			int fi = q[flag].front().first;
			int fj = q[flag].front().second;
			q[flag].pop();

			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				if (check(ki, kj) && visit[ki][kj] == 0 && v[ki][kj] != WALL) {
					if (v[ki][kj] == SHEEP)
						p.first++;
					else if (v[ki][kj] == WOLF)
						p.second++;

					q[!flag].push(make_pair(ki, kj));
					visit[ki][kj] = 1;
				}
			}

		}
		flag = !flag;
	}
	if (p.first > p.second)
		p.second = 0;
	else
		p.first = 0;

	return p;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector < vector<bool>> visit(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;

			if (c == '.')
				v[i][j] = GROUND;
			else if (c == '#')
				v[i][j] = WALL;
			else if (c == 'v')
				v[i][j] = WOLF;
			else
				v[i][j] = SHEEP;
		}
	}

	pair<int, int> p;
	int a = 0, b = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				p = bfs(i, j, v, visit);
				a += p.first;
				b += p.second;
			}
		}
	}

	cout << a << " " << b << '\n';
	return 0;
}