#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 999999999
int N, M, H;	// 세로선, 가로선, 세로선마다 가로선을 놓을 수 있는 위치의 개수

inline bool check(int i, int j) {
	if (i < 0 || j < 0 || i > H || j > N)
		return 0;
	else
		return 1;
}

pair<int, int> move(pair<int, int> p, vector<vector<int>>& v) {
	int i = p.first;
	int j = p.second;

	if (check(i, j + 1) && v[i][j] == 1)		  // 오른쪽으로
		return pair<int, int>(i + 1, j + 1);
	else if (check(i, j - 1) && v[i][j - 1] == 1) // 왼쪽으로
		return pair<int, int>(i + 1, j - 1);
	else										  // 아래로
		return pair<int, int>(i + 1, j);
}

bool execute(vector<vector<int>>& v) {
	for (int i = 1; i <= N; i++) {
		pair<int, int> p = make_pair(1, i);
		while (p.first != H + 1) {
			p = move(p, v);

		}
		if (p.second != i)
			return 0;
	}

	return 1;
}

inline bool check_line(int i, int j, vector<vector<int>>& v) {

	if (check(i, j - 1) && check(i, j) && check(i, j + 1) &
		v[i][j - 1] == 0 && v[i][j] == 0 & v[i][j + 1] == 0)
		return 1;
	else
		return 0;
}

int build(int x, int y, int line, vector<vector<int>>& v) {
	int result = 999999999;

	for (int i = x; i <= H; i++) { // 세로줄
		for (int j = 1; j < N; j++) { // 가로줄

			if (check_line(i, j, v)) {
				v[i][j] = 1;

				if (execute(v)) {
					v[i][j] = 0;
					return line;
				}

				if (line < 3)
					result = min(result, build(i, j, line + 1, v));

				v[i][j] = 0;
			}
		}
	}

	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> H;

	vector<vector<int>> v(H + 1, vector<int>(N + 1));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b; // 가로선, 세로선 번호
		v[a][b] = 1;
	}

	int line = 0;

	if (!execute(v))
		line = build(1, 1, 1, v);

	if (line == MAX)
		cout << "-1\n";
	else
		cout << line << "\n";

	return 0;
}