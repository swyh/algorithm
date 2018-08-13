#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define GEAR	4
#define LEFT	6
#define RIGHT	2

void chageGear(int dist, vector<int>& v) {
	vector<int> temp;
	if (dist == 1) {	// 시계
		temp.push_back(v[7]);
		for (int i = 0; i < 7; i++)
			temp.push_back(v[i]);
	}
	else if (dist == -1) {	// 반시계
		for (int i = 1; i < 8; i++)
			temp.push_back(v[i]);
		temp.push_back(v[0]);
	}
	v = temp;
}

bool isGear(int num) {
	if (1 <= num && num <= GEAR)
		return 1;
	else
		return 0;
}

void move(int gear, int dist, vector<bool>& visit, vector<vector<int>>& v) {
	if (visit[gear])
		return;

	visit[gear] = 1;
	int left = v[gear][LEFT];
	int right = v[gear][RIGHT];

	chageGear(dist, v[gear]);

	if (isGear(gear - 1) && v[gear - 1][RIGHT] != left) {
		move(gear - 1, -dist, visit, v);
	}
	if (isGear(gear + 1) && right != v[gear + 1][LEFT]) {
		move(gear + 1, -dist, visit, v);
	}
}

int solve() {
	int K;
	cin >> K;

	vector<vector<int>> v(GEAR + 1, vector<int>(8));

	for (int i = 1; i <= GEAR; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int gear, dist;
		cin >> gear >> dist;

		vector<bool> visit(GEAR + 1);
		move(gear, dist, visit, v);
	}


	int result = 0;

	for (int i = 1; i <= GEAR; i++) {
		result += v[i][0] * pow(2, i - 1);
	}

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << solve() << "\n";
	}

	return 0;
}