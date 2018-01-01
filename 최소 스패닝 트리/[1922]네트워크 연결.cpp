//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//vector<vector<pair<int, int>>> v;
//vector<bool> visit;
//priority_queue < pair<int, int>> pq;
//int result = 0;
//void func(int n);
//int main() {
//	int N, M;	// 컴퓨터 수, 선의 수
//	cin >> N >> M;
//	v.resize(N + 1);
//	visit.resize(N + 1);
//	for (int i = 0; i < M; i++) {
//		int v1, v2, cost;
//		cin >> v1 >> v2 >> cost;
//		v[v1].push_back(make_pair(-cost, v2));
//		v[v2].push_back(make_pair(-cost, v1));
//	}
//	func(1);
//	cout << result << endl;
//}
//
//void func(int n) {
//	visit[n] = 1;
//	for (int i = 0; i < v[n].size(); i++) {
//		pq.push(v[n][i]);
//	}
//
//	while (!pq.empty()) {
//		if (visit[pq.top().second] == 0) {
//			result += -pq.top().first;
//			func(pq.top().second);
//			break;
//		}
//		else
//			pq.pop();
//	}
//}
//
////최소스패닝 트리



//2107-12-15 다시 풀어봄
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;



int main() {
	int N, M, cnt = 0;
	cin >> N >> M;


	vector<vector<pair<int, int>>> v;
	vector<bool> visit;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	v.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c, b));
		v[b].push_back(make_pair(c, a));
	}

	visit[1] = 1;
	for (int i = 0; i < v[1].size(); i++)
		pq.push(v[1][i]);

	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (!visit[vertex]) {
			visit[vertex] = 1;
			cnt += cost;
			for (int i = 0; i < v[vertex].size(); i++) {
				if (!visit[v[vertex][i].second])
					pq.push(v[vertex][i]);
			}
		}
	}
	cout << cnt << endl;

}