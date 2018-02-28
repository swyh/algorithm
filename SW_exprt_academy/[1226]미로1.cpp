#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ki[4] = { 1, -1, 0, 0 };
int kj[4] = { 0, 0, 1, -1 };

bool error_check(int i, int j) {
	if (i < 0 || j < 0 || i > 15 || j > 15)
		return 0;
	else
		return 1;
}

int DFS(vector<vector<int>>& v, vector<vector<bool>>& visit, int i, int j) {
	visit[i][j] = 1;
	int check = 0;

	for (int k = 0; k < 4; k++) {
		int di = i + ki[k];
		int dj = j + kj[k];

		if (v[di][dj] == 3)
			return 1;

		if (error_check(di, dj) && !visit[di][dj] && v[di][dj] == 0) {
			visit[di][dj] = 1;
			if (check == 0)
				check += DFS(v, visit, di, dj);
		}
	}

	return check;
}

bool check(vector<vector<int>>& v, vector<vector<bool>>& visit) {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (v[i][j] == 2) {
				return DFS(v, visit, i, j);
			}
		}
	}
	return 0;
}

int main() {
	int T = 10;
	while (T--) {
		int num;
		cin >> num;

		vector<vector<int>> v(16);
		vector<vector<bool>> visit(16);

		for (int i = 0; i < 16; i++) {
			visit[i].resize(16);
			string s;
			cin >> s;
			for (int j = 0; j < 16; j++) {
				v[i].push_back(s[j] - 48);
			}
		}
		cout << "#" << num << " " << check(v, visit) << endl;
	}

	return 0;
}