#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int di[8] = { -2,-2,-1,-1,1,1,2,2 };
int dj[8] = { -1,1,-2,2,-2,2,-1,1 };

int l;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= l || j >= l)
		return 0;
	else
		return 1;
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		cin >> l;

		vector<vector<int>> v(l, vector<int>(l));
		vector < vector<bool>> visit(l, vector<bool>(l));

		int i, j, x, y;
		cin >> i >> j >> x >> y;

		queue<pair<int, int>> q[2];
		bool flag = 0;
		pair<int, int> p;

		q[flag].push(make_pair(i, j));

		int time = 0;
		bool exit = 0;

		while (!q[flag].empty()) {
			while (!q[flag].empty()) {
				int fi = q[flag].front().first;
				int fj = q[flag].front().second;
				q[flag].pop();

				if (fi == x && fj == y) {
					exit = 1;
					break;
				}

				for (int k = 0; k < 8; k++) {
					int ki = fi + di[k];
					int kj = fj + dj[k];



					if (check(ki, kj) && visit[ki][kj] == 0) {
						q[!flag].push(make_pair(ki, kj));
						visit[ki][kj] = 1;
					}
				}

			}
			if (exit)
				break;

			time++;
			flag = !flag;
		}
		cout << time << endl;
	}

	return 0;
}