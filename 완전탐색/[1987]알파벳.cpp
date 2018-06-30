#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int R, C;
int max_val = 0;
vector<vector<char>> v;
bool alpha[26] = { 0 };

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= R || j >= C)
		return 0;
	else
		return 1;
}

void dfs(int i, int j, int sum) {
	if (alpha[v[i][j] % 26])	// 이미 존재
		return;

	alpha[v[i][j] % 26] = true;

	for (int k = 0; k < 4; k++) {
		int ki = i + di[k];
		int kj = j + dj[k];

		if (check(ki, kj))
			dfs(ki, kj, sum + 1);
	}
	alpha[v[i][j] % 26] = false;
	max_val = max(max_val, sum);
}

int main() {
	cin >> R >> C;

	v.resize(R, vector<char>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> v[i][j];
		}
	}

	dfs(0, 0, 1);

	cout << max_val << "\n";

	return 0;
}