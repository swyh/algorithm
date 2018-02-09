#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	int row = 0, cnt = 0, max_cnt = 0, all_cnt = 0;
	cin >> n >> m;

	vector<vector<int>> v(n + 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			for (int k = 0; k < 5; k++) {
				int value = input / pow(10, k);
				if (value % 10 == 9)
					cnt++;
			}
			v[i].push_back(input);
		}
		if (cnt > max_cnt)
			max_cnt = cnt;
		all_cnt += cnt;
		cnt = 0;
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 5; k++) {
				int value = v[i][j] / pow(10, k);
				if (value % 10 == 9)
					cnt++;
			}
		}
		if (cnt > max_cnt)
			max_cnt = cnt;
		cnt = 0;
	}

	cout << all_cnt - max_cnt << endl;

}