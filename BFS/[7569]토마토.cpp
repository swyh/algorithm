#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H;
int dh[6] = { 1,-1,0,0,0,0 };
int di[6] = { 0,0,1,-1,0,0 };
int dj[6] = { 0,0,0,0,1,-1 };

class position {
public:
	int h;
	int i;
	int j;

	position(int h, int i, int j) {
		this->h = h;
		this->i = i;
		this->j = j;
	}
};

bool check(position& p) {
	if (p.h < 0 || p.i < 0 || p.j < 0 || p.h >= H || p.i >= M || p.j >= N)
		return 0;
	else
		return 1;
}

int main() {
	cin >> N >> M >> H;

	vector<vector<vector<int>>> v(H, vector<vector<int>>(M, vector<int>(N)));
	vector<vector<vector<int>>> visit(H, vector<vector<int>>(M, vector<int>(N)));

	queue<position> q[2];
	bool flag = 0;
	int sum = 0;

	for (int h = 0; h < H; h++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[h][i][j];
				if (v[h][i][j] == 1) {
					q[flag].push(position(h, i, j));
					visit[h][i][j] = 1;
				}
				else if (v[h][i][j] == 0)
					sum++;
			}
		}
	}

	int time = -1;

	while (!q[flag].empty()) {
		time++;
		while (!q[flag].empty()) {
			position p = q[flag].front();
			q[flag].pop();

			for (int k = 0; k < 6; k++) {
				position kp(p.h + dh[k], p.i + di[k], p.j + dj[k]);

				if (check(kp) && visit[kp.h][kp.i][kp.j] == 0 && v[kp.h][kp.i][kp.j] == 0) {
					visit[kp.h][kp.i][kp.j] = 1;
					v[kp.h][kp.i][kp.j] = 1;
					q[!flag].push(kp);
					sum--;
				}
			}
		}
		flag = !flag;
	}

	if (sum == 0) {
		if (time < 0)
			time = 0;
		cout << time << endl;
	}
	else
		cout << "-1" << endl;

	return 0;
}