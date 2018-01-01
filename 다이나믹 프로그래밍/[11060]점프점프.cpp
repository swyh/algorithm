//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	vector<int> arr(N+1);
//	vector<int> dp(N+1,1000);
//
//	for (int i = 1; i <= N; i++) {
//		cin >> arr[i];
//		if (i == 1)	dp[1] = -1;
//		for (int j = 1; j < i; j++) {
//			if (j+ arr[j] >= i) {
//				dp[i] = min(dp[i], dp[j]);
//			}
//		}
//		dp[i]++;
//	}
//	if (dp[N] == 1001)
//		cout << "-1" << endl;
//	else
//		cout << dp[N] << endl;
//	return 0;
//}
//


#include <iostream>
#include <algorithm>
using namespace std;

const int max_int = 10000000;
int main() {
	int arr[1001] = { 0 };
	int dp[1001] = { 0 };

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < N; i++) {
		dp[i] = max_int;
		for (int j = 0; j < i; j++) {
			if (j + arr[j] >= i)
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}

	if (dp[N - 1] == max_int)
		cout << "-1\n";
	else
		cout << dp[N - 1] << "\n";

	return 0;
}