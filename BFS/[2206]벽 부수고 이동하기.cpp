#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int N, M;

#define UNUSE	1
#define USE		2

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

class node {
public:
	int i;
	int j;
	int chance;

	node(int i, int j, int chance) {
		this->i = i;
		this->j = j;
		this->chance = chance;
	}
};

int main() {
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<int>> visit(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		cin.ignore();
		for (int j = 0; j < M; j++) {
			char input;
			input = cin.get();
			v[i][j] = input - '0';
		}
	}

	queue<node> q[2];
	bool flag = 0;

	q[flag].push(node(0, 0, UNUSE));
	visit[0][0] = 1;

	int cnt = 0;
	while (!q[flag].empty()) {
		cnt++;
		while (!q[flag].empty()) {
			int fi = q[flag].front().i;
			int fj = q[flag].front().j;
			int chance = q[flag].front().chance;
			q[flag].pop();

			if (fi == N - 1 && fj == M - 1) {
				cout << cnt << endl;
				return 0;
			}

			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				if (check(ki, kj) && !(chance & visit[ki][kj])) {
					int k_chance = chance;

					if (v[ki][kj]) {
						if (k_chance == UNUSE)
							k_chance = USE;
						else
							continue;
					}

					q[!flag].push(node(ki, kj, k_chance));

					visit[ki][kj] |= k_chance;
				}
			}
		}
		flag = !flag;
	}

	cout << "-1" << endl;
	return 0;
}