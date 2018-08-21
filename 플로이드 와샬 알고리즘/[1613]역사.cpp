#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<vector<bool>> v(n + 1, vector<bool>(n + 1));

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i][k] && v[k][j])
					v[i][j] = 1;
			}
		}
	}

	int s;
	cin >> s;

	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		if (v[a][b])
			cout << "-1\n";
		else if (v[b][a])
			cout << "1\n";
		else
			cout << "0\n";
	}

}