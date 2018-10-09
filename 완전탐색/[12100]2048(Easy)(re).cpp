#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void move_calumn(vector<int>& v) {

	int wall = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0)
			continue;

		int position = i;

		for (int j = i - 1; j >= wall; j--) {
			if (v[j] == 0) {
				swap(v[position], v[j]);
				position = j;
			}
			else {
				if (v[j] == v[position]) {
					v[j] *= 2;
					v[position] = 0;
					wall = j + 1;
				}
				break;
			}
		}
	}
}

void move(int dir, vector<vector<int>>& v) {

	vector<vector<int>> temp = v;

	for (int k = 0; k < dir; k++) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				v[j][v.size() - i - 1] = temp[i][j];
			}
		}

		temp = v;
	}

	for (int i = 0; i < v.size(); i++)
		move_calumn(v[i]);
}

int execute(vector<int>& dir, vector<vector<int>> v) {
	for (int i = 0; i < dir.size(); i++)
		move(dir[i], v);

	int max_val = 0;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			max_val = max(max_val, v[i][j]);
		}
	}

	return max_val;
}

int brute(int n, vector<int>& dir, vector<vector<int>>& v) {
	if (n == 5)
		return execute(dir, v);

	int max_val = 0;

	for (int k = 0; k < 4; k++) {
		dir[n] = k;
		max_val = max(max_val, brute(n + 1, dir, v));
	}

	return max_val;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	vector<int> dir(5);
	int answer = 0;

	for (int k = 0; k < 4; k++) {
		dir[0] = k;
		answer = max(answer, brute(1, dir, v));
	}

	cout << answer << endl;

	return 0;
}