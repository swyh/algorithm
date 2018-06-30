//all shortest path 구하기
//플로이드 와샬, 다익스트라 알고리즘으로 해결할 수 있다.
//플로이드 와샬 : O(n^3), 다익스트라 : O(nmlogn) -> transpose graph를 이용하면 O(2mlogn)에 문제 해결 가능
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NUM 999999999

int main() {
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);

	vector<vector<int>> v(N + 1, vector<int>(N + 1, MAX_NUM));

	for (int i = 0; i < M; i++) {
		int v1, v2, w;
		scanf("%d %d %d", &v1, &v2, &w);
		v[v1][v2] = w;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || v[i][k] == MAX_NUM || v[k][j] == MAX_NUM)
					continue;
				if (v[i][k] + v[k][j] < v[i][j])
					v[i][j] = v[i][k] + v[k][j];
			}
		}
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		if (v[i][X] == MAX_NUM || v[X][i] == MAX_NUM)
			continue;

		result = max(result, v[i][X] + v[X][i]);
	}

	printf("%d\n", result);

	return 0;
}