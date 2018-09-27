#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 0x0fffffff

int main() {
	int N;
	cin >> N;

	int** arr = new int*[N];
	int** dp = new int*[N];

	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		dp[i] = new int[N];

		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			dp[i][j] = MAX;
		}
	}

	for (int j = 0; j < 3; j++)
		dp[0][j] = arr[0][j];


	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j != k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + arr[i][j]);
			}
		}
	}

	int answer = MAX;
	for (int j = 0; j < 3; j++)
		answer = min(answer, dp[N - 1][j]);

	cout << answer << endl;


}