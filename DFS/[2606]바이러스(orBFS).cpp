#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<bool> visit;
int cnt = 0;

void DFS(int i) {
	if (visit[i])
		return;

	visit[i] = 1;
	cnt++;

	for (int j = 0; j < v[i].size(); j++)
		DFS(v[i][j]);
}

int main() {
	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	visit.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);
	cout << cnt - 1 << endl;
}