
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visit;
queue<pair<int, int>> q;

int kind = 0;
int M, N;
int day = 0;
int all = 0;

int check(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M || visit[x][y] == 1)
		return 0;
	else {
		return 1;
	}
}

void insert(int x, int y) {
	v[x][y] = 1;
	q.push(make_pair(x, y));
}

int BFS() {

	int qt = 0;
	int temp = 0;
	while (temp != all) {
		//cout << qt << endl;
		if (q.empty()) return -1;
		while (!q.empty()) {

			pair<int, int> p = q.front();
			temp++;
			visit[p.first][p.second] = 1;

			//cout << p.first << ", " << p.second << endl;

			if (check(p.first + 1, p.second) && v[p.first + 1][p.second] == 0) {
				insert(p.first + 1, p.second);
			}
			if (check(p.first - 1, p.second) && v[p.first - 1][p.second] == 0) {
				insert(p.first - 1, p.second);
			}
			if (check(p.first, p.second + 1) && v[p.first][p.second + 1] == 0) {
				insert(p.first, p.second + 1);
			}
			if (check(p.first, p.second - 1) && v[p.first][p.second - 1] == 0) {
				insert(p.first, p.second - 1);
			}
			q.pop();
			if (temp == kind) {
				//	cout << "up";
				qt++;
				kind = q.size() + temp;
			}
			//cout << temp << endl;
			//cout << kind << endl;

		}
		if (kind == all) return qt - 1;
	}
	return qt;
}

int main() {

	cin >> M >> N;
	all = M * N;
	v.resize(N);
	visit.resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			v[i].push_back(input);
			visit[i].push_back(0);

			if (input == 1) {
				kind++;
				q.push(make_pair(i, j));
			}
			if (input == -1) all--;
		}
	}

	if (kind == M*N) cout << "0\n";
	else if (kind == 0) cout << "-1\n";
	else {
		cout << BFS() << "\n";
	}
}