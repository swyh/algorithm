#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visit;
vector<int> area;
int area_cnt = 0;
int M, N, K;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool check(int i, int j) {
	if (i >= M || j >= N || i < 0 || j < 0 ||
		visit[i][j] == 1 || v[i][j] == 1)
		return 0;
	else
		return 1;
}

void BFS(int i, int j) {
	area_cnt++;
	int cnt = 1;
	visit[i][j] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		for (int k = 0; k < 4; k++) {
			int x = q.front().first + di[k];
			int y = q.front().second + dj[k];

			if (check(x, y)) {
				visit[x][y] = 1;
				q.push(make_pair(x, y));
				cnt++;
			}
		}
		q.pop();
	}
	area.push_back(cnt);
}


int main() {

	cin >> M >> N >> K;

	v.resize(M);
	visit.resize(M);

	for (int i = 0; i < M; i++) {
		v[i].resize(N);
		visit[i].resize(N);
	}

	for (int i = 0; i < K; i++) {
		int x, y, xd, yd;
		cin >> x >> y >> xd >> yd;

		for (int j = y; j < yd; j++) {
			for (int k = x; k < xd; k++) {
				v[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0 && v[i][j] == 0)
				BFS(i, j);
		}
	}

	cout << area_cnt << endl;

	sort(area.begin(), area.end());
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}
	cout << endl;

	return 0;

}