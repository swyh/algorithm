#include <iostream>
#include <vector>
using namespace std;

#define GROUND	0
#define WALL	1
#define OVIS	2
#define WOLF	3

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0,0,1,-1 };

int R, C;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= R || j >= C)
		return 0;
	else
		return 1;
}

pair<int, int> dfs(int i, int j, vector<vector<int>>& v, vector<vector<bool>>& visit) {
	visit[i][j] = 1;

	pair<int, int> p = make_pair(0, 0);

	if (v[i][j] == OVIS)
		p.first++;
	else if (v[i][j] == WOLF)
		p.second++;

	for (int k = 0; k < 4; k++) {
		int ki = i + di[k];
		int kj = j + dj[k];

		if (check(ki, kj) && v[ki][kj] != WALL && !visit[ki][kj]) {
			pair<int, int> temp = dfs(ki, kj, v, visit);
			p.first += temp.first;
			p.second += temp.second;
		}

	}

	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C;

	vector<vector<int>> v(R, vector<int>(C));
	vector<vector<bool>> visit(R, vector<bool>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char input;
			cin >> input;

			if (input == '.')
				v[i][j] = GROUND;
			else if (input == '#')
				v[i][j] = WALL;
			else if (input == 'o')
				v[i][j] = OVIS;
			else if (input == 'v')
				v[i][j] = WOLF;
		}
	}

	int ovis = 0, wolf = 0;
	pair<int, int> p;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visit[i][j] && v[i][j] != WALL) {
				p = dfs(i, j, v, visit);
				if (!p.first && !p.second)
					continue;
				if (p.first > p.second)
					ovis += p.first;
				else
					wolf += p.second;
			}
		}
	}

	cout << ovis << " " << wolf << "\n";

	return 0;
}