#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int BFS(vector<vector<int>>& v, vector<bool>& visit, int n) {   // i : ÇöÀç°ª
	int original = n;
	visit[n] = 1;

	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));

	while (!q.empty()) {
		int f = q.front().first;
		int cnt = q.front().second;

		for (int i = 0; i < v[f].size(); i++) {
			if (cnt != 0 && f == original) {
				return cnt;
			}
			visit[v[f][i]] = 1;
			q.push(make_pair(v[f][i], cnt + 1));
		}
		q.pop();
	}

	return 0;

}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {

		int N;
		cin >> N;

		vector<vector<int>> v(N + 1);
		vector<bool> visit(N + 1);

		for (int i = 1; i <= N; i++) {
			int input;
			cin >> input;
			v[input].push_back(i);
		}

		int result = 0;

		for (int i = 1; i <= N; i++) {
			if (!visit[i])
				result += BFS(v, visit, i);
		}
		cout << N - result << "\n";

	}
}