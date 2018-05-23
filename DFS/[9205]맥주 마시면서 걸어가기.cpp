#include <iostream>
#include <vector>
using namespace std;
#define MAX_HP 1000

bool isAdjacent(pair<int, int> p1, pair<int, int> p2) {
	if (abs(p1.first - p2.first) + abs(p1.second - p2.second) > MAX_HP)
		return 0;
	else
		return 1;
}

bool DFS(int num, int n, vector<pair<int, int>>& point, vector<bool>& visit) {
	visit[num] = 1;

	if (num == n + 1)
		return 1;

	int result = 0;
	for (int i = 0; i < n + 2; i++) {
		if (!visit[i] && isAdjacent(point[num], point[i]))
			result += DFS(i, n, point, visit);
	}
	return result;
}

void solveDFS() {
	vector<pair<int, int>> point;
	vector<bool> visit;
	int n, x, y;

	cin >> n;

	visit.resize(n + 2);
	for (int i = 0; i < n + 2; i++) {
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}

	if (DFS(0, n, point, visit))
		cout << "happy" << endl;
	else
		cout << "sad" << endl;
}

void solveFloyd() {
	int N, x, y;
	cin >> N;

	vector<pair<int, int>> v;
	vector<vector<bool>> d(N + 2, vector<bool>(N + 2));

	for (int i = 0; i < N + 2; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	for (int i = 0; i < N + 2; ++i) {
		for (int j = 0; j < N + 2; ++j) {
			if (i == j)	continue;
			else if (isAdjacent(v[i], v[j]))
				d[i][j] = 1;
		}
	}

	for (int k = 0; k < N + 2; k++) {
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				if (d[i][k] + d[k][j] == 2)
					d[i][j] = true;
			}
		}
	}

	const char* result = d[0][N + 1] ? "happy" : "sad";
	cout << result << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solveDFS();
		//solveFloyd();
	}
}