#include <iostream>
#include <vector>
using namespace std;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

int N, M;

int next(int dist) {
	if (dist == 0)
		return 3;
	else
		return dist - 1;
}

int opp(int dist) {
	if (dist == 0)
		return 2;
	else if (dist == 1)
		return 3;
	else if (dist == 2)
		return 0;
	else if (dist == 3)
		return 1;
}

int clear(int r, int c, int dist, vector<vector<int>>& v) {

	int cnt = 1;
	v[r][c] = 2;
	bool move;

	while (1) {

		move = 0;
		for (int k = 0; k < 4; k++) {
			dist = next(dist);
			int ki = r + di[dist];
			int kj = c + dj[dist];

			if (v[ki][kj] == 0) {
				r = ki;
				c = kj;
				v[r][c] = 2;
				cnt++;

				move = 1;
				break;
			}
		}
		
		if (move)
			continue;

		r = r + di[opp(dist)];
		c = c + dj[opp(dist)];

		if (v[r][c] == 1)
			break;
	}

	return cnt;
}

int main() {

	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int>> v(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	cout << clear(r, c, d, v) << "\n";
	return 0;
}