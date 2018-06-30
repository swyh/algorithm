#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> depth;
vector<int> visit;
vector<int> parent;

void dfs(int i, int p) {
	if (visit[i] == 1)
		return;
	visit[i] = 1;
	parent[i] = p;

	for (int j = 0; j < v[i].size(); j++)
		dfs(v[i][j], i);
}

int main() {
	int N;
	scanf("%d", &N);
	v.resize(N + 1);
	visit.resize(N + 1);
	parent.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int a1, a2;
		scanf("%d%d", &a1, &a2);
		v[a1].push_back(a2);
		v[a2].push_back(a1);
	}

	dfs(1, 1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}