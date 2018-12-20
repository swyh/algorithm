#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> v(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		v[i][1] = 1;
		v[i][i] = 1;

		for (int j = 1; j < i; j++) {
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
		}
	}

	cout << v[n][k] << endl;

	return 0;
}