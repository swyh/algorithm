#include <iostream>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

inline int D(int i) {
	return  2 * i % 10000;
}

inline int S(int i) {
	return (10000 + i - 1) % 10000;
}

inline int L(int i) {
	return ((i % 1000) * 10) + (i / 1000);
}

inline int R(int i) {
	return ((i % 10) * 1000) + (i / 10);
}
int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	char s[4] = { 'D', 'S', 'L', 'R' };

	while (T--) {
		int A, B;
		cin >> A >> B;

		string visit[10000];
		queue<int> q[2];
		bool flag = 0;
		bool exit = 0;
		int cnt = -1;

		q[flag].push(A);

		while (!q[flag].empty()) {
			cnt++;

			while (!q[flag].empty()) {
				int i = q[flag].front();
				q[flag].pop();

				int di[4] = { D(i), S(i), L(i), R(i) };

				for (int k = 0; k < 4; k++) {
					if (di[k] == i)
						continue;

					if (visit[di[k]].empty()) {
						visit[di[k]] = visit[i] + s[k];

						q[!flag].push(di[k]);

						if (di[k] == B) {
							exit = 1;
							break;
						}
					}
				}
				if (exit)
					break;
			}
			if (exit)
				break;

			flag = !flag;

		}
		cout << visit[B] << "\n";
	}

	return 0;
}