#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NON	0
#define ME	1
#define YOU	2

vector<vector<int>> v;
vector<bool> visit;
int C, H, K;

pair<int, int> dfs(int n) {
	if (visit[n])
		return make_pair(0, 0);


	visit[n] = 1;

	pair<int, int> cnt_flag = make_pair(1, 0);
	if (n == C)
		cnt_flag.second = ME;
	else if (n == H)
		cnt_flag.second = YOU;

	for (int i = 0; i < v[n].size(); i++) {

		cnt_flag.first += dfs(v[n][i]).first;
		cnt_flag.second += dfs(v[n][i]).second;
	}

	return cnt_flag;
}

int main() {
	int N, M;
	cin >> N >> M;

	v.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		v[X].push_back(Y);
		v[Y].push_back(X);
	}

	cin >> C >> H >> K;

	int max_ = 0;
	priority_queue<int> pq;

	for (int i = 1; i <= N; i++) {
		pair<int, int> result = dfs(i);
		if (result.second == ME)
			max_ += result.first;
		else if (result.second == YOU)
			continue;
		else
			pq.push(result.first);
	}

	while (!pq.empty() && K > 0) {
		max_ += pq.top();

		pq.pop();
		K--;
	}

	cout << max_ << endl;

}