#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	int result = 0;
	for (int k = 0; k <= N; k++) {
		vector<int> dp(N);

		int result1 = 0;
		int conn = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j])
					dp[i] = max(dp[i], dp[j]);
			}
			dp[i]++;
			result1 = max(result1, dp[i]);
			conn = max(conn, arr[i]);
		}
		int result2 = 0;
		for (int i = k; i < N; i++) {
			for (int j = k; j < i; j++) {
				if (arr[i] < arr[j])
					dp[i] = max(dp[i], dp[j]);
			}
			if (conn != arr[i])
				dp[i]++;
			result2 = max(result2, dp[i]);
		}

		result = max(result, result1 + result2);
	}
	cout << result << endl;
	return 0;
}