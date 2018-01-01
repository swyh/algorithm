#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;



int main() {
	int N, M, cnt = 0;
	cin >> N >> M;


	vector<vector<pair<int, int>>> v;
	vector<bool> visit;
	priority_queue<int> num;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	v.resize(N + 1);
	visit.resize(N + 1);


	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c, b));
		v[b].push_back(make_pair(c, a));
	}

	visit[1] = 1;
	for (int i = 0; i < v[1].size(); i++)
		pq.push(v[1][i]);

	int cost, vertex;

	while (!pq.empty()) {
		vertex = pq.top().second;
		cost = pq.top().first;
		pq.pop();

		if (!visit[vertex]) {
			visit[vertex] = 1;
			num.push(cost);
			cnt += cost;
			for (int i = 0; i < v[vertex].size(); i++) {
				if (!visit[v[vertex][i].second])
					pq.push(v[vertex][i]);
			}
		}
	}
	cout << cnt - num.top() << endl;

}