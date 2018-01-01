//pair로 각 정점에서 depth를 갖게 했음. 비효율적이다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, a, b, m;
	cin >> n;
	cin >> a >> b;
	cin >> m;

	vector<vector<int>> v;
	vector<bool> visit;
	queue<pair<int, int>> q;

	v.resize(n + 1);
	visit.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	int cnt = 0;

	q.push(make_pair(0, a));
	visit[a] = 1;

	while (!q.empty()) {
		int level = q.front().first;
		int z = q.front().second;
		q.pop();

		if (z == b) {
			cnt = level;
			break;
		}

		for (int i = 0; i < v[z].size(); i++) {
			if (visit[v[z][i]] == 0) {
				visit[v[z][i]] = 1;
				q.push(make_pair(level + 1, v[z][i]));
			}
		}

	}

	if (cnt == 0)
		cout << "-1" << endl;
	else
		cout << cnt << endl;

	return 0;
}