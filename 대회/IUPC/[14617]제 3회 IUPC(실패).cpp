#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };
int N;

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N)
		return 0;
	else
		return 1;
}

int cost(int i, int j) {
	int result = v[i][j];
	for (int k = 0; k < 4; k++) {
		if (check(i + di[k], j + dj[k]))
			result += v[i + di[k]][j + dj[k]];
		else
			return -1;
	}
	return result;
}

int main() {
	cin >> N;

	v.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		v[i].resize(N);
		dp[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = cost(i, j);
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
		}
	}


}