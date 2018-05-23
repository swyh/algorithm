#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> arr(N + 1);
	vector<int> dp(N + 1);	// 최대비용

	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;
		arr[i] = make_pair(t, p);
	}

	//first : 걸리는 시간, second : 비용
	if (arr[1].first <= N)
		dp[1] = arr[1].second;
	else
		dp[1] = 0;

	//이 날 상담을 할 때 최대값 (상담 불가능 하면 0)
	for (int i = 2; i <= N; i++) {
		if (arr[i].first > N - i + 1) continue;

		dp[i] = arr[i].second;

		for (int j = 1; j <= N; j++) {
			if (j + arr[j].first <= i)	// 날짜가 되는지
				dp[i] = max(dp[j] + arr[i].second, dp[i]);
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		result = max(result, dp[i]);
	}
	cout << result << endl;
}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//
//	vector<int> day(N + 1);
//	vector<int> cost(N + 1);
//	vector<int> dp(N + 1);
//
//	for (int i = 1; i <= N; i++) {
//		cin >> day[i] >> cost[i];
//	}
//
//	for (int i = 1; i <= N; i++) {
//		if (i + day[i] - 1 > N) continue;
//
//		dp[i] = cost[i];
//
//		for (int j = 1; j < i; j++) {
//			if (j + day[j] - 1 < i)
//				dp[i] = max(dp[i], cost[i] + dp[j]);
//		}
//	}
//
//	int max_ = 0;
//	for (int i = 1; i <= N; i++) {
//		max_ = max(max_, dp[i]);
//	}
//	cout << max_ << endl;
//}