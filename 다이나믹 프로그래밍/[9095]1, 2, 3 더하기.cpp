#include <iostream>
using namespace std;


int dp[11]{ 0,1,2,4, 0 };

int solve(int N) {
	if (dp[N] != 0)
		return dp[N];

	dp[N] = solve(N - 1) + solve(N - 2) + solve(N - 3);

	return dp[N];
}

int main() {
	int T;
	cin >> T;


	while (T--) {
		int input;
		cin >> input;

		cout << solve(input) << "\n";
	}
}