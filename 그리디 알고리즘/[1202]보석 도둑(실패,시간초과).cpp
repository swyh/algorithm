#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int N, K, result = 0; // 보석, 가방
	scanf("%d %d", &N, &K);

	vector<pair<int, int>> v;
	vector<int> bag;
	vector<bool> visit(N + 1);

	for (int i = 0; i < N; i++) {
		int weight, cost;
		scanf("%d %d", &weight, &cost);
		v.push_back(make_pair(cost, weight));
	}

	for (int i = 0; i < K; i++) {
		int weight;
		scanf("%d", &weight);
		bag.push_back(weight);
	}
	sort(v.begin(), v.end(), greater<>());
	sort(bag.begin(), bag.end());

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			if (bag[i] >= v[j].second && visit[j] == 0) {
				result += v[j].first;
				visit[j] = 1;
				break;
			}
		}
	}
	printf("%d\n", result);
}