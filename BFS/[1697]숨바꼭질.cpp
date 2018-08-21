#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	if (N == K) {
		cout << 0 << "\n";
		return 0;
	}

	int time = 0;
	bool visit[100001] = { 0 };
	queue<int> q[2];
	bool flag = 0;
	int di[3] = { 1,-1, 0 };

	q[flag].push(N);
	visit[N] = 1;


	while (!q[flag].empty()) {
		time++;
		while (!q[flag].empty()) {
			int i = q[flag].front();
			q[flag].pop();

			di[2] = i;

			for (int k = 0; k < 3; k++) {
				int ki = i + di[k];

				if (0 <= ki && ki <= 100000 && !visit[ki]) {

					if (ki == K) {
						cout << time << "\n";
						return 0;
					}

					visit[ki] = 1;
					q[!flag].push(ki);
				}
			}
		}
		flag = !flag;
	}
}