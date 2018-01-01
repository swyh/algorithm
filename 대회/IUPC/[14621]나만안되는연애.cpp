#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<char> sex;
vector <vector<pair<int, int>>> v;
vector<bool> visit;
priority_queue <pair<int, int>> pq;
int result = 0;
int cnt = 0;
void func(int n);

int main() {
	int N, M;
	cin >> N >> M;

	v.resize(N + 1);
	visit.resize(N + 1);
	sex.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> sex[i];
	}

	for (int i = 0; i < M; i++) {
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;

		if (sex[v1] != sex[v2]) {
			v[v1].push_back(make_pair(-cost, v2));
			v[v2].push_back(make_pair(-cost, v1));
		}
	}
	func(1);
	if (cnt == N)
		cout << result << endl;
	else
		cout << "-1" << endl;
	return 0;
}

void func(int n) {
	cnt++;
	visit[n] = 1;
	for (int i = 0; i < v[n].size(); i++) {
		pq.push(v[n][i]);
	}
	while (!pq.empty()) {
		if (visit[pq.top().second] == 0){
			result += -pq.top().first;
			func(pq.top().second);
		}
		else
			pq.pop();
	}
}