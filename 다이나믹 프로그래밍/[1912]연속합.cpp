#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> dp(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];

	int result = dp[0];

	for (int i = 1; i < N; i++) {
		if (dp[i - 1] >= 0)
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
		result = max(result, dp[i]);
	}
	cout << result << endl;

	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	int A[100001] = {};
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}
	int partsum[100] = { 0, };
	int k = 1;
	int check = 0;
	int max1 = partsum[1];
	for (int i = 1; i <= n; i++)
	{
		if (A[i] >= 0)
		{
			partsum[k] = partsum[k] + A[i];
			check = 1;
		}
		else
		{
			k++;
		}
		max1 = max(partsum[k], max1);

	}
	if (check == 0)
	{
		for (int a = 1; a <= n; a++)
		{
			max1 += A[a];
		}
	}
	cout << max1 << endl;
	return 0;
}