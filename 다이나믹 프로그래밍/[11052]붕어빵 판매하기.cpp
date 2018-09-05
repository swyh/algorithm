#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[1001] = { 0 };
	int dp[1001] = { 0 };
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		arr[i] = input;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], arr[j] + dp[i - j]);
		}
	}
	cout << dp[N] << endl;
}