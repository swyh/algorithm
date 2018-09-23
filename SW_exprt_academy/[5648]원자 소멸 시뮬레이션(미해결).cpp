#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define COLLISION	-1

int di[4] = { 1, -1,0,0 };
int dj[4] = { 0,0,-1,1 };

inline bool check(int i, int j) {
	if (i < 0 || j < 0 || i > 2000 || j > 2000)
		return 0;
	else
		return 1;
}

class Node {
public:
	int i;
	int j;
	int dir;
	int k;

	Node(int i, int j, int dir, int k) {
		this->i = i;
		this->j = j;
		this->dir = dir;
		this->k = k;
	}
};

int main() {

	ios::sync_with_stdio(false);
	int T;
	cin >> T;


	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<vector<int>> v(2001, vector<int>(2001));
		queue<Node> q[2];
		queue<pair<int, int>> collision;
		bool flag = 0;
		int time = 1;
		int answer = 0;

		for (int i = 0; i < N; i++) {
			int x, y, dir, k;
			cin >> x >> y >> dir >> k;
			v[y + 1000][x + 1000] = time;
			q[flag].push(Node(y + 1000, x + 1000, dir, k));
		}


		while (!q[flag].empty()) {
			time++;
			while (!q[flag].empty()) {
				Node node = q[flag].front();
				q[flag].pop();

				if (v[node.i][node.j] == COLLISION) {
					answer += node.k;
					v[node.i][node.j] = 0;
					continue;
				}

				int ki = node.i + di[node.dir];
				int kj = node.j + dj[node.dir];

				if (check(ki, kj)) {

					if (v[ki][kj] != time && v[ki][kj] != COLLISION) {	// move
						v[ki][kj] = time;
						q[!flag].push(Node(ki, kj, node.dir, node.k));
					}
					else if (v[ki][kj] == time) { // Ãæµ¹
						v[ki][kj] = COLLISION;
						answer += node.k;
					}
					else if (v[ki][kj] == COLLISION) {
						answer += node.k;
					}
				}
			}

			flag = !flag;
		}


		cout << "#" << t << " " << answer << "\n";
	}
	return 0;
}
