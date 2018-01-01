#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<bool> visit;
vector<int> v_cnt;
int cnt = 0, max_cnt = 0;

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
	v_cnt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;	// a가 b를 신뢰한다.
		v[b].push_back(a);	// b를 신뢰하는 목록에 a를 넣음
	}

	for (int i = 1; i <= n; i++) {
		DFS(i);
		v_cnt[i] = cnt;
		max_cnt = max(max_cnt, cnt);
		cnt = 0;
		for (int i = 1; i <= n; i++)
			visit[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (max_cnt == v_cnt[i])
			cout << i << " ";
	}
	cout << endl;

}