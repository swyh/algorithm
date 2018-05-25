#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, max_val = 0;
	cin >> n;
	vector<int> v;
	vector<int> dp(n);

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < n; i++) {	// 최대 증가하는 수열을 구한다.
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		max_val = max(max_val, dp[i]);
	}

	cout << n - max_val << endl;
}