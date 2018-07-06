#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define NULL	0
#define WALL	1
#define VIRUS	2

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

int N, M, max_val = 0, space = 0;


bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

int bfs(int i, int j, vector<vector<int>>& v, vector<vector<bool>>& visit) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = true;

	int virus = 0;

	while (!q.empty()) {
		int qi = q.front().first;
		int qj = q.front().second;
		for (int k = 0; k < 4; k++) {
			int ki = qi + di[k];
			int kj = qj + dj[k];
			if (check(ki, kj) && !visit[ki][kj] && v[ki][kj] == NULL) {
				q.push(make_pair(ki, kj));
				visit[ki][kj] = true;
			}
		}
		q.pop();
		virus++;
	}

	return virus;
}

int spreads_virus(vector<vector<int>>& v) {
	int virus = 0;
	vector<vector<bool>> visit(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] != VIRUS || visit[i][j] == true)
				continue;

			virus += bfs(i, j, v, visit);
		}
	}

	return virus;
}

void set_wall(int wall_number, vector<vector<int>>& v) {
	if (wall_number == 3) {
		int virus = spreads_virus(v);
		max_val = max(max_val, space - virus - 3);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] != NULL)
				continue;

			v[i][j] = WALL;
			set_wall(wall_number + 1, v);
			v[i][j] = NULL;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M;
	space = N * M;
	vector<vector<int>> v(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == WALL)
				space--;
		}
	}

	set_wall(0, v);
	cout << max_val << endl;
}