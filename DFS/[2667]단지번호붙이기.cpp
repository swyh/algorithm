

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool visitCheck(int x, int y);
void DFS(int x, int y);
vector<vector<int>> v;
vector<vector<bool>> visit;
vector<int> sum;
int n;
int cnt = 0;
int main() {

	cin >> n;
	v.resize(n);
	visit.resize(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			visit[i].push_back(0);
			v[i].push_back(s[j] - '0');
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			DFS(i, j);
			if (cnt != 0) {
				sum.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(sum.begin(), sum.end());
	cout << sum.size() << "\n";

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i] << "\n";
	}

}
bool visitCheck(int x, int y) {
	if (x >= n || x < 0 || y >= n || y < 0 || visit[x][y] == 1)
		return 0;
	else
		return 1;
}

void DFS(int x, int y) {

	if (v[x][y] == 1 && visit[x][y] == 0) {
		visit[x][y] = 1;
		if (visitCheck(x - 1, y))
			DFS(x - 1, y);
		if (visitCheck(x + 1, y))
			DFS(x + 1, y);
		if (visitCheck(x, y - 1))
			DFS(x, y - 1);
		if (visitCheck(x, y + 1))
			DFS(x, y + 1);
		cnt += 1;
	}
}
