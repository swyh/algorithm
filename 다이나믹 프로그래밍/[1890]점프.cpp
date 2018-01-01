#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long arr[100][100] = { 0 };
	long long dp[100][100] = { 0 };

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			int jump = arr[i][j];
			if (i == N - 1 && j == N - 1) break;
			if (i + jump < N)
				dp[i + jump][j] += dp[i][j];
			if (j + jump < N)
				dp[i][j + jump] += dp[i][j];
		}
	}

	cout << dp[N - 1][N - 1] << endl;

}