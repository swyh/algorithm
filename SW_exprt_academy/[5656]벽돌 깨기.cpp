
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 0x0fffffff

int N, W, H; // 1~4, 2~12, 2~15
int min_val;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= H || j >= W)
		return 0;
	else
		return 1;
}

int boom(int i, int j, vector<vector<int>>& v) {
	int boom_block = 1;
	int cnt = v[i][j];
	v[i][j] = 0;

	if (cnt > 1) {
		for (int k = 0; k < 4; k++) {
			for (int m = 1; m < cnt; m++) {
				int ki = i + di[k] * m;
				int kj = j + dj[k] * m;

				if (check(ki, kj) && v[ki][kj] != 0)
					boom_block += boom(ki, kj, v);
				else
					continue;
			}
		}
	}

	return boom_block;
}

void print_v(vector<vector<int>>& v) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void execute(int cnt, int n, int block, vector<vector<int>> v) {
	if (cnt == N + 1) {
		min_val = min(min_val, block);
		return;
	}

	bool flag = 0;
	for (int i = 0; i < H; i++) {
		if (v[i][n] != 0) {
			block -= boom(i, n, v);
			flag = 1;
			break;
		}
	}

	if (!flag) {
		min_val = min(min_val, block);
		return;
	}

	//print_v(v);
	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) {
			for (int k = 0; k < H - i - 1; k++) {
				if (v[k][j] > 0 && v[k + 1][j] == 0)
					swap(v[k][j], v[k + 1][j]);
			}
		}
	}
	//print_v(v);

	for (int i = 0; i < W; i++) {
		execute(cnt + 1, i, block, v);
	}

}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		min_val = MAX;
		int block = 0;
		cin >> N >> W >> H;

		vector<vector<int>> v(H, vector<int>(W));

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> v[i][j];
				if (v[i][j] > 0)
					block++;
			}
		}

		for (int i = 0; i < W; i++) {
			execute(1, i, block, v);
		}
		cout << "#" << t << " " << min_val << "\n";
	}
}
