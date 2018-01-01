
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int cnt = 0;
int root = 0;
vector<vector<bool>> v;
vector<vector<bool>> visit;
vector<vector<int>> dp;
vector<queue<pair<int, int>>> q;
bool check(int i, int j, int dt) {
	if (i >= N || j >= M || i < 0 || j < 0 || !v[i][j] || visit[i][j])
		return false;
	else {
		cnt++;
		visit[i][j] = 1;
		q[dt + 1].push(make_pair(i, j));
		return true;
	}
}

int BFS(int i, int j) {
	q.resize(N*M);
	int dt = 1;
	q[dt].push(make_pair(i, j));
	while (cnt != root) {
		while (!q[dt].empty()) {
			pair<int, int> n = q[dt].front();

			check(n.first + 1, n.second, dt);
			check(n.first - 1, n.second, dt);
			check(n.first, n.second + 1, dt);
			check(n.first, n.second - 1, dt);
			q[dt].pop();
			if (n == pair<int, int>(N - 1, M - 1))
				return dt;
		}
		dt++;
	}
	return dt;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;

	v.resize(N);
	visit.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			v[i].push_back(s[j] - '0');
			visit[i].push_back(0);
			dp[i].push_back(0);
			if (s[j] - '0') root++;
		}
	}
	cout << BFS(0, 0) << "\n";
}