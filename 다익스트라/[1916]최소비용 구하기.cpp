#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define UNSEEN	0
#define FRINGE	1
#define TREE	2
#define INF		0x0fffffff

class Dijkstra {
private:
	vector<int> state;
	vector<int> predecessor;
	priority_queue<pair<int, int>>pq;

	void insert(int n);
	int removeMin();

public:
	void execute(int n);
	vector<vector<pair<int, int>>> graph;
	vector<int> dist;

	Dijkstra(int v_size) {
		graph.resize(v_size + 1);
		state.resize(v_size + 1, UNSEEN);
		dist.resize(v_size + 1, INF);
		predecessor.resize(v_size + 1, -1);
		priority_queue<pair<int, int>>pq;
	}

};

void Dijkstra::insert(int n) {	// n과 인접한 노드 fringe로 ( n은 Tree가 됨)
	state[n] = TREE;

	for (int i = 0; i < graph[n].size(); i++) {
		int v = graph[n][i].first; // 연결된 vertex
		int cost = graph[n][i].second;

		if (state[v] == UNSEEN) {	// insert
			dist[v] = dist[n] + cost;
			pq.push(make_pair(-dist[v], v));

			state[v] = FRINGE;
			predecessor[v] = n;
		}
		else if (state[v] == FRINGE) { // decreaseKey()
			if (dist[n] + cost < dist[v]) {

				dist[v] = dist[n] + cost;
				pq.push(make_pair(-dist[v], v));

				predecessor[v] = n;
			}
		}
	}
}

int Dijkstra::removeMin() {	// O(logn)
	int min_cost, min_idx;

	while (1) {
		if (pq.empty())
			return -1;

		min_cost = -pq.top().first;	// -cost, idx
		min_idx = pq.top().second;

		pq.pop();

		if (state[min_idx] != TREE)
			break;
	}

	state[min_idx] = TREE;
	dist[min_idx] = min_cost;

	return min_idx;
}

void Dijkstra::execute(int n) {

	dist[n] = 0;	// 시작지점
	insert(n);		// 시작지점 insert

	while (!pq.empty()) {
		int min_idx = removeMin();
		if (min_idx != -1)
			insert(min_idx);
	}
}

int main() {
	int v, e;
	scanf("%d %d", &v, &e);


	Dijkstra dijkstra(v);

	for (int i = 0; i < e; i++) {
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		dijkstra.graph[v1].push_back(make_pair(v2, cost));
	}

	int start, end;
	scanf("%d %d", &start, &end);

	dijkstra.execute(start);

	printf("%d\n", dijkstra.dist[end]);

	return 0;
}