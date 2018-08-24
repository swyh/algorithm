#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define GROUND	0
#define WALL	1
#define ME		2
#define FIRE	3

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0,0,1,-1 };

int R, C;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= R || j >= C)
		return 0;
	else
		return 1;
}

bool move(queue<pair<int, int>> q[], vector<vector<int>>& visit, vector<vector<int>>& v, int flag, int type) {
	while (!q[flag].empty()) {
		int fi = q[flag].front().first;
		int fj = q[flag].front().second;
		q[flag].pop();

		if (type == ME && visit[fi][fj] == FIRE)
			continue;

		for (int k = 0; k < 4; k++) {
			int ki = fi + di[k];
			int kj = fj + dj[k];

			if (type == ME) {
				if (!check(ki, kj))
					return 1;

				if (visit[ki][kj] == 0 && v[ki][kj] == GROUND) {
					q[!flag].push(make_pair(ki, kj));
					visit[ki][kj] = ME;
					v[ki][kj] = ME;
				}
			}
			else if (type == FIRE) {
				if (check(ki, kj) && visit[ki][kj] != FIRE && v[ki][kj] != WALL) {
					q[!flag].push(make_pair(ki, kj));
					visit[ki][kj] = FIRE;
					v[ki][kj] = FIRE;
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
	queue<pair<int, int>> fq[2];
	bool flag = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char input;
			cin >> input;

			if (input == '.')
				v[i][j] = GROUND;
			else if (input == '#')
				v[i][j] = WALL;
			else if (input == 'J') {
				v[i][j] = ME;
				mq[flag].push(make_pair(i, j));
				visit[i][j] = ME;
			}
			else if (input == 'F') {
				v[i][j] = FIRE;
				fq[flag].push(make_pair(i, j));
				visit[i][j] = FIRE;
			}
		}
	}
	bool success = 0;
	int time = 1;
	while (!mq[flag].empty()) {
		if (move(mq, visit, v, flag, ME)) {
			success = 1;
			break;
		}
		move(fq, visit, v, flag, FIRE);

		flag = !flag;
		time++;
	}

	if (success)
		cout << time << "\n";
	else
		cout << "IMPOSSIBLE\n";

	return 0;
}