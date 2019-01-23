#include <iostream>
#include <algorithm>
using namespace std;


int n, max_value = 0;

int v[501][501] = { 0 };
int dp[501][501] = { 0 };

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

int check(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		return 0;
	else
		return 1;
}

int dfs(int i, int j) {

	if (dp[i][j] == 0) {
		dp[i][j] = 1;

		for (int k = 0; k < 4; k++) {
			int ki = i + di[k];
			int kj = j + dj[k];

			if (check(ki, kj) && v[ki][kj] > v[i][j])
				dp[i][j] = max(dp[i][j], dfs(ki, kj) + 1);
		}
	}
	return dp[i][j];
}

int main() {
	cin >> n;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_value = max(max_value, dfs(i, j));
		}
	}

	cout << max_value << endl;

	return 0;

}