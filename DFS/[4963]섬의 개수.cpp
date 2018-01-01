
#include <iostream>
#include <vector>
using namespace std;

int w, h;
bool being = 0;
int cnt = 0;
vector<vector<bool>> v;
vector<vector<bool>> visit;

bool check(int x, int y) {
	if (x >= h || y >= w || 0 > x || 0 > y || visit[x][y] || !v[x][y])
		return 0;
	else
		return 1;
}

void DFS(int x, int y) {
	if (check(x, y)) {
		visit[x][y] = 1;
		being = 1;
		if (check(x, y + 1))
			DFS(x, y + 1);
		if (check(x, y - 1))
			DFS(x, y - 1);
		if (check(x + 1, y))
			DFS(x + 1, y);
		if (check(x - 1, y))
			DFS(x - 1, y);
		if (check(x - 1, y - 1))
			DFS(x - 1, y - 1);
		if (check(x - 1, y + 1))
			DFS(x - 1, y + 1);
		if (check(x + 1, y - 1))
			DFS(x + 1, y - 1);
		if (check(x + 1, y + 1))
			DFS(x + 1, y + 1);
	}
}

int main() {

	while (cin >> w >> h) {
		if (!w && !h) break;
		v.resize(h);
		visit.resize(h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				bool sum;
				cin >> sum;
				v[i].push_back(sum);
				visit[i].push_back(0);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				DFS(i, j);
				if (being) {
					cnt++;
					being = 0;
				}
			}
		}
		v.clear();
		visit.clear();
		cout << cnt << "\n";
		cnt = 0;
	}
}
