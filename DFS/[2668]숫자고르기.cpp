#include <iostream>
#include <vector>
using namespace std;

bool dfs(int start, int i, vector<int>& v, vector<bool>& visit) {
	visit[i] = 1;
	int next = v[i];

	if (start == next)
		return 1;

	bool check = 0;

	if (!visit[next])
		check = dfs(start, next, v, visit);

	if (!check)
		visit[i] = 0;

	return check;
}

int main() {
	int N;
	cin >> N; // max : 100

	vector<int> v(N + 1);
	vector<bool> visit(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i])
			dfs(i, i, v, visit);
	}

	int max_val = 0;

	for (int i = 1; i <= N; i++) {
		if (visit[i])
			max_val++;
	}

	cout << max_val << endl;
	for (int i = 1; i <= N; i++) {
		if (visit[i])
			cout << i << endl;
	}
}