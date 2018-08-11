#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, C, L;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0, 1,-1 };
bool set[8][4] = { { 0,0,0,0 },{ 1,1,1,1 },{ 1,1,0,0 },{ 0,0,1,1 },{ 0,1,1,0 },{ 1,0,1,0 },{ 1,0,0,1 },{ 0,1,0,1 } };

int check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

int opposite(int i) {
	if (i == 0)
		return 1;
	else if (i == 1)
		return 0;
	else if (i == 2)
		return 3;
	else if (i == 3)
		return 2;
}

int bfs(vector<vector<int>>& v) {
	vector<vector<bool>> visit(N, vector<bool>(M));
	vector<queue<pair<int, int>>> vq(2);

	vq[0].push(make_pair(R, C));
	visit[R][C] = 1;

	bool flag = 0;
	int time = 0;
	int position = 0;

	while (1) {
		time++;
		while (!vq[flag].empty()) {
			int i = vq[flag].front().first;
			int j = vq[flag].front().second;
			int type = v[i][j];

			vq[flag].pop();
			position++;

			for (int k = 0; k < 4; k++) {
				int ki = i + di[k];
				int kj = j + dj[k];

				if (!check(ki, kj))
					continue;

				int type_op = v[ki][kj];

				if (!visit[ki][kj] && v[ki][kj] && set[type][k] && set[type_op][opposite(k)]) {
					visit[ki][kj] = 1;
					vq[!flag].push(make_pair(ki, kj));
				}
			}
		}

		flag = !flag;

		if (vq[flag].empty() || time == L)
			break;
	}
	/*
	cout << endl;
	cout << endl;
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
	cout << visit[i][j] << " ";
	}
	cout << endl;
	}*/
	return position;
}

int solve() {
	cin >> N >> M >> R >> C >> L;

	vector<vector<int>> v(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	return bfs(v);
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << solve() << "\n";
	}

	return 0;
}