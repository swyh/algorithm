#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int max_val = 0;
vector<vector<int>> v;
vector<vector<int>> visit;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

//pi, pj는 재귀 이전의 i,j
void DFS(int pi, int pj, int i, int j, int cnt, int sum) {
	visit[i][j] = true;

	sum += v[i][j];

	if (cnt < 4) {
		if (cnt == 3) {
			for (int k = 0; k < 4; k++) {
				int ki = pi + di[k];
				int kj = pj + dj[k];
				if (check(ki, kj) && !visit[ki][kj]) {
					DFS(i, j, ki, kj, cnt + 1, sum);
				}
			}
		}

		for (int k = 0; k < 4; k++) {
			int ki = i + di[k];
			int kj = j + dj[k];

			if (check(ki, kj) && !visit[ki][kj]) {
				DFS(i, j, ki, kj, cnt + 1, sum);
			}
		}
	}
	else
		max_val = max(max_val, sum);

	visit[i][j] = false;
}

int main() {

	cin >> N >> M;

	v.resize(N);
	visit.resize(N);

	for (int i = 0; i < N; i++) {
		visit[i].resize(M);
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			v[i].push_back(input);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			DFS(i, j, i, j, 1, 0);
		}
	}

	cout << max_val << endl;
}