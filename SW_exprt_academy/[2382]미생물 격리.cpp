#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int di[5] = { 0, -1,1,0,0 };
int dj[5] = { 0, 0,0,-1,1 };
//상 하 좌 우 1 2 3 4

bool check(int i, int j) {
	if (i <= 0 || j <= 0 || i >= N - 1 || j >= N - 1)
		return 1;
	else
		return 0;
}

int chage(int i) {
	if (i == 1)
		return 2;
	else if (i == 2)
		return 1;
	else if (i == 3)
		return 4;
	else if (i == 4)
		return 3;
}

int foo() {
	cin >> N >> M >> K;

	vector<vector<pair<int, int>>> v(N, vector<pair<int, int>>(N));

	for (int k = 0; k < K; k++) {
		int i, j, n, d; // i, j, 미생물 수, 이동방향
		cin >> i >> j >> n >> d;
		v[i][j] = make_pair(n, d);
	}

	while (M--) {
		vector<vector<pair<int, int>>> temp(N, vector<pair<int, int>>(N));
		vector<vector<int>> max_val(N, vector<int>(N));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j].first == 0)
					continue;

				int n = v[i][j].first;
				int d = v[i][j].second;
				int ki = i + di[d];
				int kj = j + dj[d];

				if (check(ki, kj)) {    // redzone
					n /= 2;
					d = chage(d);
				}

				if (max_val[ki][kj] < n) {   // 방향 바꾸기
					max_val[ki][kj] = n;
					temp[ki][kj].second = d;
				}

				temp[ki][kj].first += n;

			}
		}
		v = temp;
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += v[i][j].first;
		}
	}

	return result;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << foo() << "\n";
	}
	return 0;
}