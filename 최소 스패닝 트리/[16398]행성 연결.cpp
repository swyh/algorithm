#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

//Prim Algorithm

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));
	vector<bool> visit(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	long long all_cost = 0;
	visit[0] = true;

	for (int i = 1; i < N; i++) {
		pq.push(make_pair(v[0][i], i));
	}

	while (!pq.empty()) {
		int cost = pq.top().first;
		int dest = pq.top().second;
		pq.pop();

		if (!visit[dest]) {
			visit[dest] = true;
			all_cost += cost;

			for (int i = 1; i < N; i++) {
				if (dest != i && !visit[i])
					pq.push(make_pair(v[dest][i], i));
			}
		}
	}

	cout << all_cost << endl;
	return 0;
}