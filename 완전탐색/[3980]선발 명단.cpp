#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_val;

void dfs(int num, int sum, vector<vector<int>>& v, vector<bool>& visit) {
	if (num == 11) {
		max_val = max(max_val, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (v[num][i] != 0 && visit[i] == 0) {

			visit[i] = 1;
			dfs(num + 1, sum + v[num][i], v, visit);
			visit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		max_val = 0;
		vector<vector<int>> v(11, vector<int>(11));
		vector<bool> visit(11);

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> v[i][j];
			}
		}

		dfs(0, 0, v, visit);
		cout << max_val << "\n";

	}
	return 0;
}