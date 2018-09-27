#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int* arr = new int[N];
	int* dp = new int[N] {0};

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = dp[0] + arr[1];
	dp[2] = arr[2] + max(dp[0], arr[1]);

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[N - 1] << endl;

}