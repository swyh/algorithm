#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0, 1,-1 };

int N, M;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

int bfs(int i, int j, vector<vector<int>>& v) {

	int max_val = 0;
	vector<vector<int>> visit(N, vector<int>(M));

	for (int water = 1; v[i][j] + water <= 9; water++) {

		int max_water = v[i][j] + water;
		int sum = water;

		queue<pair<int, int>> q[2];
		bool flag = 0;

		q[flag].push(make_pair(i, j));
		visit[i][j] = water;

		try {
			while (!q[flag].empty()) {
				while (!q[flag].empty()) {
					int fi = q[flag].front().first;
					int fj = q[flag].front().second;
					q[flag].pop();

					for (int k = 0; k < 4; k++) {
						int ki = fi + di[k];
						int kj = fj + dj[k];

						if (!check(ki, kj))
							throw 1;
						else if (visit[ki][kj] != water &&
							v[ki][kj] < max_water) {
							visit[ki][kj] = water;
							q[!flag].push(make_pair(ki, kj));
							sum += max_water - v[ki][kj];
						}

					}
				}
				flag = !flag;
			}
		}
		catch (int x) {
			sum = 0;
		}
		max_val = max(max_val, sum);
	}

	return max_val;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		cin.ignore();
		for (int j = 0; j < M; j++) {
			char input;
			input = cin.get();
			v[i][j] = input - '0';
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer = max(answer, bfs(i, j, v));
		}
	}
	cout << answer << endl;

	return 0;
}