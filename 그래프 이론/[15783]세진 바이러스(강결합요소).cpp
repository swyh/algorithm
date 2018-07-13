#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> v_t;
vector<bool> visit;
stack<int> s;

void dfs(int n) {
	if (visit[n])
		return;
	visit[n] = 1;

	for (int i = 0; i < v[n].size(); i++)
		dfs(v[n][i]);

	s.push(n);
}

void dfs2(int n) {
	if (visit[n])
		return;
	visit[n] = 1;

	for (int i = 0; i < v[n].size(); i++)
		dfs(v[n][i]);

}

int main() {
	int N, M;
	cin >> N >> M;

	v.resize(N);
	v_t.resize(N);
	visit.resize(N);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;	// A->B
		v[A].push_back(B);
		v_t[B].push_back(A);
	}


	for (int i = 0; i < N; i++) {
		if (!visit[i])
			dfs(i);
	}

	for (int i = 0; i < N; i++)
		visit[i] = 0;

	int cnt = 0;
	while (!s.empty()) {
		int i = s.top();
		s.pop();
		if (!visit[i]) {
			dfs2(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}