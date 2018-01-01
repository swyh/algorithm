#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int adj[1001][1001] = { 0 };
int dist[1001] = { 0 };
int visit[1001] = { 0 };
int n, m;
const int int_max = 2147483647;

void BFS(int i) {

	queue<int> q;
	q.push(i);
	dist[i] = 0;

	while (!q.empty()) {
		int x = q.front();

		for (int j = 1; j <= n; j++) {
			if (adj[x][j] != -1 && visit[j] == 0) {
				q.push(j);
				visit[j] = 1;
			}
			if (adj[x][j] != -1)
				dist[j] = min(dist[j], dist[x] + adj[x][j]);
		}
		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			adj[i][j] = -1;
		}
		dist[i] = int_max;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (adj[a][b] != -1)
			adj[a][b] = min(adj[a][b], c);
		else
			adj[a][b] = c;
	}

	int s, d;
	cin >> s >> d;

	BFS(s);

	cout << dist[d] << "\n";
}