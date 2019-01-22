
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> v;
vector<bool> visit;

void dfs(int n) {
	visit[n] = 1;

	cout << n << " ";

	for (int i = 0; i < v[n].size(); i++) {
		if (!visit[v[n][i]])
			dfs(v[n][i]);
	}
}

void bfs(int n) {
	queue<int> q[2];
	bool flag = 0;
	q[flag].push(n);
	visit[n] = 1;


	while (!q[flag].empty()) {
		while (!q[flag].empty()) {
			int fi = q[flag].front();
			q[flag].pop();

			cout << fi << " ";

			for (int i = 0; i < v[fi].size(); i++) {
				if (!visit[v[fi][i]]) {
					q[!flag].push(v[fi][i]);
					visit[v[fi][i]] = 1;
				}
			}
		}
		flag = !flag;
	}
}

int main() {
	cin >> N >> M >> V;

	v.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(V);
	cout << endl;
	for (int i = 1; i <= N; i++)
		visit[i] = 0;

	bfs(V);
	cout << endl;
}