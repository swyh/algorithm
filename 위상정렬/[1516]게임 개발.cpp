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
	int N;
	cin >> N;

	v.resize(N + 1);
	v_time.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int num = 0;
		cin >> v_time[i];
		while (1) {
			cin >> num;
			if (num == -1)
				break;
			v[i].push_back(num);
		}

	}

	for (int i = 1; i <= N; i++) {
		cout << DFS(i) << endl;
	}

}