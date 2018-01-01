//time out

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--) {
		int F;
		cin >> F;

		map<string, vector<string>> m;
		queue<string> q;

		for (int i = 0; i < F; i++) {
			int cnt = 0;
			map<string, bool> visit;

			string a, b;
			cin >> a >> b;

			m[a].push_back(b);
			m[b].push_back(a);

			for (int i = 0; i < m[a].size(); i++) {
				if (visit[m[a][i]] == 0) {
					visit[m[a][i]] = 1;
					q.push(m[a][i]);
				}
			}

			while (!q.empty()) {
				string t = q.front();

				for (int i = 0; i < m[t].size(); i++) {
					if (visit[m[t][i]] == 0) {
						visit[m[t][i]] = 1;
						q.push(m[t][i]);
					}
				}
				q.pop();
				cnt++;
			}

			cout << cnt << "\n";
		}
	}
}