#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WELL	6
#define VISIT	9
int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };

int N, M;

inline int opposite(int dir) {
	return (dir + 2) % 4;
}

inline int right(int dir) {
	return (dir + 1) % 4;
}

inline int left(int dir) {
	return (dir + 3) % 4;
}

void change(int i, int j, int dir, vector<vector<int>>& v) {

	while (1) {
		i = i + di[dir];
		j = j + dj[dir];

		if (i < 0 || j < 0 || i >= N || j >= M || v[i][j] == WELL)
			break;
		else if (v[i][j] == 0) {
			v[i][j] = VISIT;
		}
	}
}

int calculate(vector<int>& type,
	vector<vector<int>> v, vector<pair<int, int>>& camera) {

	for (int n = 0; n < camera.size(); n++) {
		int i = camera[n].first;
		int j = camera[n].second;

		change(i, j, type[n], v);

		if (v[i][j] == 2)
			change(i, j, opposite(type[n]), v);
		else if (v[i][j] == 3)
			change(i, j, left(type[n]), v);
		else if (v[i][j] == 4) {
			change(i, j, left(type[n]), v);
			change(i, j, opposite(type[n]), v);
		}
		else if (v[i][j] == 5) {
			change(i, j, opposite(type[n]), v);
			change(i, j, right(type[n]), v);
			change(i, j, left(type[n]), v);
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

int execute(int cnt, vector<int>& type,
	vector<vector<int>>& v, vector<pair<int, int>>& camera) {

	if (cnt == camera.size())
		return calculate(type, v, camera);

	int value = 0x0fffffff;
	for (int k = 0; k < 4; k++) {
		type[cnt] = k;
		value = min(value, execute(cnt + 1, type, v, camera));
	}

	return value;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	vector<pair<int, int>> camera;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] != 0 && v[i][j] != WELL)
				camera.push_back(make_pair(i, j));
		}
	}

	int answer = 0;
	vector<int> type(camera.size());
	answer = execute(0, type, v, camera);

	cout << answer << endl;

	return 0;
}