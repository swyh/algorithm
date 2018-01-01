#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector <vector<bool>> visit;
vector<vector<int>> depth;
queue<pair<int, int>> q;
int N, M;
int year = 0;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else {
		return 1;
	}
}

bool BFS(int i, int j) {
	if (check(i, j) && v[i][j] != 0 && visit[i][j] == 0) {

		q.push(make_pair(i, j));
		visit[i][j] = 1;

		while (!q.empty()) {
			for (int k = 0; k < 4; k++) {
				int x = q.front().first + di[k];
				int y = q.front().second + dj[k];

				if (check(x, y) && v[x][y] != 0 && visit[x][y] == 0) {
					q.push(make_pair(x, y));
					visit[x][y] = 1;
				}
			}
			q.pop();
		}
		return 1;
	}
	else
		return 0;
}

void thaw(int i, int j) {
	if (v[i][j] != 0) {
		for (int k = 0; k < 4; k++) {
			int x = i + di[k];
			int y = j + dj[k];

			if (check(x, y) && v[i][j] != 0 && v[x][y] == 0 && depth[x][y] != year) {
				v[i][j]--;
			}
		}
		if (v[i][j] == 0) {
			depth[i][j] = year;
		}
	}
}

void visitClear_Thaw() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
			thaw(i, j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	v.resize(N);
	visit.resize(N);
	depth.resize(N);
	for (int i = 0; i < N; i++) {
		v[i].resize(M);
		visit[i].resize(M);
		depth[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	int cnt = 0;
	do {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cnt += BFS(i, j);
			}
		}
		if (cnt >= 2)
			break;
		else {
			year++;
			visitClear_Thaw();
		}
	} while (cnt != 0);

	if (cnt != 0)
		cout << year << "\n";
	else
		cout << 0 << "\n";
	return 0;
}