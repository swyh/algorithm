#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//1,2,4,8 : ¼­,ºÏ,µ¿,³²
int di[4] = { 0,-1, 0,1 };
int dj[4] = { -1,0,1,0 };
int m, n;
int cnt_room = 0;
int max_room = 0;
int mer_room = 0;
vector<int> v_room(2501);


bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= m || j >= n)
		return 0;
	else
		return 1;
}

void bfs(int i, int j, vector<vector<int>>& v, vector<vector<int>>& visit) {
	cnt_room++;
	queue<pair<int, int>> q[2];
	bool flag = 0;

	visit[i][j] = cnt_room;
	q[flag].push(make_pair(i, j));
	int room = 0;

	while (!q[flag].empty()) {
		while (!q[flag].empty()) {
			int fi = q[flag].front().first;
			int fj = q[flag].front().second;
			q[flag].pop();
			room++;

			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				bool wall = v[fi][fj] & (1 << k);

				if (check(ki, kj) && !wall && !visit[ki][kj]) {
					visit[ki][kj] = cnt_room;
					q[!flag].push(make_pair(ki, kj));
				}
			}
		}
		flag = !flag;
	}
	v_room[cnt_room] = room;
	max_room = max(max_room, room);
}

int main() {
	cin >> n >> m;

	vector<vector<int>> v(m, vector<int>(n));
	vector<vector<int>> visit(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j])
				bfs(i, j, v, visit);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j + 1) && visit[i][j] != visit[i][j + 1])
				mer_room = max(mer_room, v_room[visit[i][j]] + v_room[visit[i][j + 1]]);

			if (check(i + 1, j) && visit[i][j] != visit[i + 1][j])
				mer_room = max(mer_room, v_room[visit[i][j]] + v_room[visit[i + 1][j]]);
		}
	}

	cout << cnt_room << "\n" << max_room << "\n" << mer_room << "\n";
}
