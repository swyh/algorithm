#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<bool>> v;
vector<vector<int>> dist;
vector<vector<int>> visit;
queue<pair<int, int>> q;
int N, result = 10001, num = 1;

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check(int i, int j) {	// 범위확인
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

int DFS(int i, int j) {
	if (check(i, j) && v[i][j] == 1 && visit[i][j] == 0) {
		visit[i][j] = num;
		for (int k = 0; k < 4; k++) {
			DFS(i + di[k], j + dj[k]);
		}
		return 1;
	}
	else
		return 0;
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> p = q.front();
		for (int k = 0; k < 4; k++) {
			if (check(p.first + di[k], p.second + dj[k]) && v[p.first + di[k]][p.second + dj[k]] == 0) {
				q.push(make_pair(p.first + di[k], p.second + dj[k]));
				v[p.first + di[k]][p.second + dj[k]] = 1;
				dist[p.first + di[k]][p.second + dj[k]] = dist[p.first][p.second] + 1;
				visit[p.first + di[k]][p.second + dj[k]] = visit[p.first][p.second];
			}
			if (check(p.first + di[k], p.second + dj[k]) && v[p.first + di[k]][p.second + dj[k]] == 1
				&& visit[p.first][p.second] != visit[p.first + di[k]][p.second + dj[k]]) {

				result = min(result, dist[p.first][p.second] + dist[p.first + di[k]][p.second + dj[k]]);

			}
		}
		q.pop();
	}
}

int main() {
	cin >> N;

	v.resize(N);
	dist.resize(N);
	visit.resize(N);

	for (int i = 0; i < N; i++) {
		v[i].resize(N);
		dist[i].resize(N);
		visit[i].resize(N);
		for (int j = 0; j < N; j++) {
			bool input;
			cin >> input;
			v[i][j] = input;

			if (input)
				q.push(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (DFS(i, j)) num++;

		}
	}

	BFS();

	cout << result << "\n";

}