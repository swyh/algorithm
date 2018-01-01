#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;
	vector<int > dp(N);

	int result = 0;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++;
		result = max(result, dp[i]);
	}
	cout << result << endl;
	return 0;
}