#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int N, M;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

bool frash(int i, int j,
	vector<vector<int>>& v, vector<vector<int>>& visit) {
	visit[i][j] = 1;
	int result = 1;

	for (int k = 0; k < 4; k++) {
		int ki = i + di[k];
		int kj = j + dj[k];

		if (!check(ki, kj))
			return 0;
		else if (visit[ki][kj])
			continue;
		else if (v[ki][kj] == 0) {
			result = frash(ki, kj, v, visit);
			if (result == 0)
				return 0;
		}
	}
	return result;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	queue<pair<int, int>> q[2];
	bool flag = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];

			if (v[i][j] == 1)
				q[flag].push(make_pair(i, j));
		}
	}

	int time = 0;
	while (!q[flag].empty()) {
		time++;
		vector<vector<int>> temp = v;

		while (!q[flag].empty()) {

			int fi = q[flag].front().first;
			int fj = q[flag].front().second;
			q[flag].pop();

			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				if (check(ki, kj) && v[ki][kj] == 0) {
					vector<vector<int>> visit(N, vector<int>(M));
					if (!frash(ki, kj, v, visit))
						cnt++;
				}
			}

			if (cnt >= 2)
				temp[fi][fj] = 0;
			else
				q[!flag].push(make_pair(fi, fj));
		}

		v = temp;
		flag = !flag;
	}

	cout << time << endl;
	return 0;
}