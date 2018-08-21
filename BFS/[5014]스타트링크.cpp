#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;

	vector<int> v(F + 1);
	vector<bool> visit(F + 1);
	char* fail = "use the stairs\n";
	int di[2] = { U, -D };

	queue<int> q[2];
	int flag = 0;
	visit[S] = 1;
	q[flag].push(S);

	int cnt = -1;
	bool success = 0;

	while (1) {
		cnt++;
		while (!q[flag].empty()) {
			int i = q[flag].front();
			q[flag].pop();

			if (i == G) {
				success = 1;
				break;
			}

			for (int k = 0; k < 2; k++) {
				int ki = i + di[k];

				if (1 <= ki && ki <= F && !visit[ki]) {
					visit[ki] = 1;
					q[!flag].push(ki);
				}
			}
		}

		flag = !flag;

		if (success || q[flag].empty())
			break;
	}

	if (success)
		cout << cnt << "\n";
	else
		cout << fail;

	return 0;
}