#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int A, B, N, M;
	cin >> A >> B >> N >> M;

	vector<bool> visit(100001);
	queue<int> q[2];
	bool flag = 0;
	q[flag].push(N);
	visit[N] = 1;

	int time = 1;

	try {
		while (!q[flag].empty()) {
			while (!q[flag].empty()) {
				int fi = q[flag].front();
				q[flag].pop();

				int di[8] = { fi + 1, fi - 1, fi + A, fi + B, fi - A, fi - B, fi * A, fi * B };

				for (int k = 0; k < 8; k++) {
					int ki = di[k];

					if (0 <= ki && ki <= 100000 && visit[ki] == 0) {

						if (ki == M)
							throw time;

						q[!flag].push(ki);
						visit[ki] = 1;
					}
				}

			}
			flag = !flag;
			time++;
		}
	}
	catch (int i) {
		cout << i << "\n";
	}

	return 0;
}

