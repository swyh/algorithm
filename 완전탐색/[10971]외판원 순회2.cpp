#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long min_val = 99999999999;

void solve(int num, long long sum, int cnt, int start, vector<vector<int>>& v, vector<bool>& visit) {

	for (int i = 0; i < v[num].size(); i++) {

		int value = v[num][i];

		if (!value)
			continue;

		if (cnt == N && i == start) {
			min_val = min(min_val, sum + value);
			return;
		}

		if (!visit[i]) {
			visit[i] = 1;
			solve(i, sum + value, cnt + 1, start, v, visit);
			visit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));
	vector<bool> visit(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		solve(i, 0, 1, i, v, visit);
		visit[i] = 0;
	}

	cout << min_val << "\n";

}