#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> visit;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };


void extend(int N) {
	v.resize(N);
	visit.resize(N);
	for (int i = 0; i < N; i++) {
		v[i].resize(N);
		visit[i].resize(N);
	}
}

void clear(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}

bool check(int i, int j, int N) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

int BFS(int i, int j, int water, int N) {

	visit[i][j] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		for (int k = 0; k < 4; k++) {
			int x = q.front().first + di[k];
			int y = q.front().second + dj[k];
			if (check(x, y, N) && visit[x][y] == 0 && water < v[x][y]) {
				q.push(make_pair(x, y));
				visit[x][y] = 1;
			}
		}
		q.pop();
	}

	return 1;
}

int main() {
	int N;
	cin >> N;

	extend(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	int result = 0;

	for (int water = 0; water <= 100; water++) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0 && water < v[i][j])
					temp += BFS(i, j, water, N);
			}
		}
		result = max(temp, result);
		clear(N);
	}

	cout << result << endl;

	return 0;
}

