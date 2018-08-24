#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define GROUND	0
#define WATER	1
#define STONE	2
#define HOME	3
#define ME		4

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int R, C;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= R || j >= C)
		return 0;
	else
		return 1;
}

bool move(queue<pair<int, int>> q[], bool flag,
	vector<vector<int>>& v, vector<vector<int>>& visit, int type) {

	while (!q[flag].empty()) {
		int fi = q[flag].front().first;
		int fj = q[flag].front().second;
		q[flag].pop();

		if (visit[fi][fj] != type)
			continue;

		for (int k = 0; k < 4; k++) {
			int ki = fi + di[k];
			int kj = fj + dj[k];

			if (!check(ki, kj))
				continue;

			if (type == ME) {
				if (v[ki][kj] == HOME)
					return 1;
				else if (v[ki][kj] == GROUND && visit[ki][kj] == 0) {
					visit[ki][kj] = ME;
					q[!flag].push(make_pair(ki, kj));
				}
			}
			else if (type == WATER) {
				if ((v[ki][kj] == GROUND || v[ki][kj] == ME) && visit[ki][kj] != WATER) {
					visit[ki][kj] = WATER;
					q[!flag].push(make_pair(ki, kj));
				}
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C;

	vector<vector<int>> v(R, vector<int>(C));
	vector<vector<int>> visit(R, vector<int>(C));

	queue<pair<int, int>> mq[2];
	queue<pair<int, int>> wq[2];
	bool flag = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;

			if (c == '.')
				v[i][j] = GROUND;
			else if (c == '*') {
				v[i][j] = WATER;
				wq[flag].push(make_pair(i, j));
				visit[i][j] = WATER;
			}
			else if (c == 'X')
				v[i][j] = STONE;
			else if (c == 'D')
				v[i][j] = HOME;
			else if (c == 'S') {
				v[i][j] = ME;
				mq[flag].push(make_pair(i, j));
				visit[i][j] = ME;
			}
		}
	}

	bool success = 0;
	int time = 1;

	while (!mq[flag].empty()) {
		if (move(mq, flag, v, visit, ME)) {
			success = 1;
			break;
		}
		move(wq, flag, v, visit, WATER);
		flag = !flag;
		time++;
	}

	if (success)
		cout << time << "\n";
	else
		cout << "KAKTUS\n";
}