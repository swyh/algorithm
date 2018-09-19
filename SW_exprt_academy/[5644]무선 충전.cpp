#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int pi[5] = { 0, -1,0,1,0 };
int pj[5] = { 0, 0, 1, 0, -1 };

pair<int, int> move(pair<int, int> p, int dir) {
	return make_pair(p.first + pi[dir], p.second + pj[dir]);
}
bool check(int i, int j) {
	if (0 >= i || 0 >= j || 10 < i || 10 < j)
		return 0;
	else
		return 1;
}

void bfs(int n, int i, int j, int c, int p,
	vector<vector<pair<int, int>>>& v, vector<vector<pair<int, int>>>& power) {

	bool flag = 0;
	queue<pair<int, int>> q[2];

	q[flag].push(make_pair(i, j));
	if (power[i][j].first < p) {
		v[i][j].second = v[i][j].first;
		power[i][j].second = power[i][j].first;

		v[i][j].first = n;
		power[i][j].first = p;
	}
	else if (power[i][j].second < p) {
		v[i][j].second = n;
		power[i][j].second = p;
	}


	int level = 0;
	while (!q[flag].empty()) {
		if (level == c)
			break;

		level++;

		while (!q[flag].empty()) {
			int fi = q[flag].front().first;
			int fj = q[flag].front().second;
			q[flag].pop();

			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				if (check(ki, kj) && (v[ki][kj].first != n && v[ki][kj].second != n)) {
					if (power[ki][kj].first < p) {
						v[ki][kj].second = v[ki][kj].first;
						power[ki][kj].second = power[ki][kj].first;

						v[ki][kj].first = n;
						power[ki][kj].first = p;
					}
					else if (power[ki][kj].second < p) {
						v[ki][kj].second = n;
						power[ki][kj].second = p;
					}
					q[!flag].push(make_pair(ki, kj));
				}

			}
		}
		flag = !flag;
	}
}

int charge(pair<int, int> p1, pair<int, int> p2,
	vector<vector<pair<int, int>>>& v, vector<vector<pair<int, int>>>& power) {
	int result = 0;
	int use_number = 0;

	result += power[p1.first][p1.second].first;
	use_number = v[p1.first][p1.second].first;

	if (v[p2.first][p2.second].first == use_number)
		result += max(power[p2.first][p2.second].second, power[p1.first][p1.second].second);
	else
		result += power[p2.first][p2.second].first;

	return result;
}

void print_v(
	vector<vector<pair<int, int>>>& v, vector<vector<pair<int, int>>>& power) {

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << v[i][j].first << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << setw(3) << power[i][j].first << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << setw(3) << power[i][j].second << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int M, A;	// 이동 시간, BC 개수
		cin >> M >> A;

		vector<int> user[2];
		vector<vector<pair<int, int>>> v(11, vector<pair<int, int>>(11));
		vector<vector<pair<int, int>>> power(11, vector<pair<int, int>>(11));

		for (int u = 0; u < 2; u++) {
			for (int i = 0; i < M; i++) {
				int input;
				cin >> input;
				user[u].push_back(input);
			}
		}

		for (int n = 1; n <= A; n++) {
			int i, j, c, p;
			cin >> j >> i >> c >> p;
			bfs(n, i, j, c, p, v, power);
		}

		//print_v(v, power);
		int result = 0;

		pair<int, int> p1 = make_pair(1, 1);
		pair<int, int> p2 = make_pair(10, 10);
		result += charge(p1, p2, v, power);

		for (int n = 0; n < M; n++) {
			p1 = move(p1, user[0][n]);
			p2 = move(p2, user[1][n]);

			result += charge(p1, p2, v, power);
		}

		cout << "#" << t << " " << result << endl;
	}
}