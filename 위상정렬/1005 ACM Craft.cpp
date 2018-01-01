#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> v_time;
vector<bool> visit;


int DFS(int i) {
	if (visit[i] == 1)
		return v_time[i];

	visit[i] = 1;

	int  time_max = 0;
	for (int j = 0; j < v[i].size(); j++)
		time_max = max(time_max, DFS(v[i][j]));
	v_time[i] += time_max;
	//cout << i << " : " << v_time[i] << " + " << time_max << endl;
	return v_time[i];
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		int N, K;
		cin >> N >> K;

		v.resize(N + 1);
		v_time.resize(N + 1);
		visit.resize(N + 1);

		for (int i = 1; i <= N; i++)
			cin >> v_time[i];

		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y; //X를 지은 다음 Y 지을 수 있음.
			v[Y].push_back(X);

		}

		int W;
		cin >> W;

		cout << DFS(W) << endl;

		for (int i = 0; i <= N; i++) {
			visit.clear();
			v.clear();
		}
	}
}