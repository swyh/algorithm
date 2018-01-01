#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
bool arr[501] = { 0 };
vector<vector<int>> v;

void check(int i) {
	for (int k = 0; k < v[i].size(); k++) {
		if (arr[v[i][k]] == 0) {

			arr[v[i][k]] = 1;
			cnt++;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	arr[1] = 1;
	for (int i = 0; i < v[1].size(); i++) {
		arr[v[1][i]] = 1;
		cnt++;
	}

	for (int i = 0; i < v[1].size(); i++) {
		check(v[1][i]);
	}

	cout << cnt << endl;
}