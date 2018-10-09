#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MINE	1
#define APPLE	2

int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };

int main() {
	int N, K, L; // 판 크기, 사과 개수, 뱀의 방향
	cin >> N >> K;

	vector<vector<int>> v(N + 1, vector<int>(N + 1));

	for (int n = 0; n < K; n++) {
		int i, j;
		cin >> i >> j;
		v[i][j] = APPLE;
	}

	priority_queue<pair<int, char>> change;
	cin >> L;

	for (int n = 0; n < L; n++) {
		int sec;
		char dir;
		cin >> sec >> dir;
		change.push(make_pair(-sec, dir));
	}

	int sec = 0;

	queue<pair<int, int>> beam;
	beam.push(make_pair(1, 1));
	v[1][1] = MINE;

	int dir = 0;

	while (1) {
		if (!change.empty() && -change.top().first == sec) {
			char char_dir = change.top().second;
			change.pop();

			if (char_dir == 'L') // 왼쪽
				dir = (dir + 3) % 4;
			else // 오른쪽
				dir = (dir + 1) % 4;
		}

		sec++;

		int si = beam.back().first + di[dir];
		int sj = beam.back().second + dj[dir];

		if (si == 0 || sj == 0 || si > N || sj > N || v[si][sj] == MINE)
			break;


		int item = v[si][sj];

		v[si][sj] = MINE;
		beam.push(make_pair(si, sj));

		if (item != APPLE) {
			v[beam.front().first][beam.front().second] = 0;
			beam.pop();
		}
	}

	cout << sec << endl;

	return 0;
}