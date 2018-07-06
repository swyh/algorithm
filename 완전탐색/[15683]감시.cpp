#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOOK	9
#define UNLOOK	0
#define WALL	6

int N, M, min_val = 99999999;
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

int check_look(vector<vector<int>>& v) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == UNLOOK)
				cnt++;
		}
	}
	return cnt;
}

void look(int i, int j, int dist, int type, int key, vector<vector<int>>& v) {
	int value = type * key;
	int opp = (type == UNLOOK) ? LOOK * key : UNLOOK;
	while (1) {
		i = i + di[dist];
		j = j + dj[dist];

		if (!check(i, j) || v[i][j] == WALL)
			break;

		if (v[i][j] == opp)
			v[i][j] = value;
		else
			continue;
	}
}
void look_cctv(int i, int j, int dist, int type, int key, vector<vector<int>>& v) {
	int cctv_type = v[i][j];
	int right = (dist + 1) % 4;
	int opp = (dist + 2) % 4;
	int left = (dist + 3) % 4;

	look(i, j, dist, type, key, v);

	if (cctv_type == 2)
		look(i, j, opp, type, key, v);
	else if (cctv_type == 3)
		look(i, j, left, type, key, v);
	else if (cctv_type == 4) {
		look(i, j, left, type, key, v);
		look(i, j, right, type, key, v);
	}
	else if (cctv_type == 5) {
		look(i, j, opp, type, key, v);
		look(i, j, left, type, key, v);
		look(i, j, right, type, key, v);
	}
}

void rotate_cctv(int num, vector<vector<int>>& v, vector<pair<int, int>>& cctv) {
	if (num == cctv.size()) {
		min_val = min(min_val, check_look(v));
		return;
	}

	for (int k = 0; k < 4; k++) {
		look_cctv(cctv[num].first, cctv[num].second, k, LOOK, num + 1, v);
		rotate_cctv(num + 1, v, cctv);
		look_cctv(cctv[num].first, cctv[num].second, k, UNLOOK, num + 1, v);

		if (v[cctv[num].first][cctv[num].second] == 5)
			break;
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector<pair<int, int>> cctv;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] != 0 && v[i][j] != 6)
				cctv.push_back(make_pair(i, j));
		}
	}

	rotate_cctv(0, v, cctv);

	cout << min_val << endl;
}