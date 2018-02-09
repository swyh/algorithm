#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

int N;
int cnt = 0;
vector<vector<int>> v;
vector<vector<int>> visit;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

void BFS(int i, int j) {
	int color = v[i][j];
	queue<pair<int, int>> q;

	visit[i][j] = 1;

	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		for (int k = 0; k < 4; k++) {
			int ki = x + di[k];
			int kj = y + dj[k];
			if (check(ki, kj) && !visit[ki][kj] && color == v[ki][kj]) {
				visit[ki][kj] = 1;
				q.push(make_pair(ki, kj));
			}
		}
		q.pop();
	}
	cnt++;
}

int main() {

	cin >> N;


	v.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < N; i++) {
		visit[i].resize(N + 1);
		for (int j = 0; j < N; j++) {
			int num;
			char input;
			cin >> input;

			switch (input) {
			case 'R':
				num = 1;
				break;
			case 'B':
				num = 2;
				break;
			case 'G':
				num = 3;
				break;
			}
			v[i].push_back(num);
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0)
				BFS(i, j);
		}
	}
	cout << cnt << " ";
	cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
			if (v[i][j] == 1)
				v[i][j] = 3;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				BFS(i, j);
			}
		}
	}
	cout << cnt << endl;

}