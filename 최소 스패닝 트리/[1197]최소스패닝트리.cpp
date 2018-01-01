//#include <iostream>
//#include <vector>
//#include <queue>
//#include <functional>
//using namespace std;
//
//vector <vector<pair<int, int>>> arr;	// 그래프에 비용을 함께 저장한다.
//vector<bool> visit;
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// (페어, 자료구조, 정렬)
//// greater : 오름차순?
//void func(int n);
//int result = 0;
//
//int main() {
//	int v, e;
//	cin >> v >> e;
//
//	arr.resize(v + 1);
//	visit.resize(v + 1);
//	for (int i = 0; i < e; i++) {
//		int v1, v2, cost;
//		cin >> v1 >> v2 >> cost;
//		arr[v1].push_back(make_pair(cost, v2));
//		arr[v2].push_back(make_pair(cost, v1));
//	}
//	func(1);
//	cout << result << endl;
//
//}
//
//void func(int n) { // 푸림 알고리즘
//	visit[n] = 1;
//	for (int i = 0; i < arr[n].size(); i++) {
//		pq.push(arr[n][i]);
//	}
//
//	while (!pq.empty()) {
//		if (visit[pq.top().second] == 0) {
//			result += pq.top().first;
//			func(pq.top().second);
//		}
//		else
//			pq.pop();
//	}
//}

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

vector<vector<pair<int, int>>> arr;
vector<bool> visit;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cnt = 0;

void func(int i) {
	visit[i] = 1;
	for (int j = 0; j < arr[i].size(); j++)
		pq.push(arr[i][j]);

	while (!pq.empty()) {
		int cost = pq.top().first;
		int dest = pq.top().second;
		pq.pop();

		if (visit[dest] == 0) {
			visit[dest] = 1;
			cnt += cost;
			for (int j = 0; j < arr[dest].size(); j++) {
				if (visit[arr[dest][j].second] == 0)
					pq.push(arr[dest][j]);
			}
		}
	}

}

int main() {
	int v, e;
	cin >> v >> e;	// v : vertex의 수, e : edge의 수

	arr.resize(v + 1);
	visit.resize(v + 1);

	for (int i = 0; i < e; i++) {
		int a, b, c;	// a, b vertex 사이의 cost
		cin >> a >> b >> c;

		arr[a].push_back(make_pair(c, b));
		arr[b].push_back(make_pair(c, a));
	}

	func(1);	// 프림 알고리즘
	cout << cnt << endl;

}