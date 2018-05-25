#include <iostream>
#include <algorithm>
#define MAX_INT 999999999
using namespace std;

int main() {
	int v[101][101] = { 0 };
	int n, m; // 도시의 개수, 버스의 개수
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				v[i][j] = 0;
			else
				v[i][j] = MAX_INT;
		}
	}

	for (int i = 0; i < m; i++) {
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		v[v1][v2] = min(v[v1][v2], cost);
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == MAX_INT)
				v[i][j] = 0;
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

}