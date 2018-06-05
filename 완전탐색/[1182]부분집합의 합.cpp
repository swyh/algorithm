#include <iostream>
#include <vector>
using namespace std;

int n, s, cnt = 0;
vector<int> v;

void dfs(int k, int sum) {
	sum += v[k];

	if (sum == s)
		cnt++;


	for (int i = k + 1; i < n; i++) {
		dfs(i, sum);
	}
	sum -= v[k];
}

int main() {
	cin >> n >> s;

	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 0);
	}

	cout << cnt << endl;

	return 0;
}