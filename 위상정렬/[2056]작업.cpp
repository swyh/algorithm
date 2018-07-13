#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> times;
vector<vector<int>> v;
vector<bool> visit;

int dfs(int n) {
	if (visit[n])
		return times[n];

	visit[n] = 1;

	int max_ = times[n];
	for (int i = 0; i < v[n].size(); i++) {
		max_ = max(max_, times[n] + dfs(v[n][i]));
	}
	times[n] = max_;

	return times[n];
}

int main() {
	int N;
	cin >> N;

	times.resize(N + 1);
	v.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int time, pre;
		cin >> time >> pre;

		times[i] = time;

		for (int j = 0; j < pre; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}

	for (int i = 1; i <= N; i++)
		dfs(i);

	int max_ = 0;
	for (int i = 1; i <= N; i++) {
		max_ = max(max_, times[i]);
	}
	cout << max_ << endl;

}