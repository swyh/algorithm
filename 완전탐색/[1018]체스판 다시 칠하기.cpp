#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check_change(char type, int x, int y, vector<vector<char>>& v) {
	int cnt = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {

			if ((i % 2 == 0 && j % 2 == 0) || i % 2 == 1 && j % 2 == 1) {
				if (type != v[i][j])
					cnt++;
			}
			else {
				if (type == v[i][j])
					cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<char>> v(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	int answer = 0x0fffffff;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			answer = min(answer, check_change('W', i, j, v));
			answer = min(answer, check_change('B', i, j, v));
		}
	}

	cout << answer << endl;
}