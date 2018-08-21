#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPrime(int num) {
	if (num <= 1)
		return 0;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return 0;
	}

	return 1;
}

bool check(int i, int j) { // 3자리 동일

	int cnt = 0;
	int k = 1;
	for (int k = 1; k <= 1000; k = k * 10) {
		if (((i % (k * 10)) / k) == ((j % (k * 10)) / k))
			cnt++;
	}

	if (cnt == 3)
		return 1;
	else
		return 0;
}

int main() {
	ios::sync_with_stdio(false);
	vector<int> v;

	for (int i = 1000; i <= 9999; i++) {
		if (isPrime(i))
			v.push_back(i);
	}

	int T;
	cin >> T;

	while (T--) {
		int A, B;
		cin >> A >> B;

		queue<int> q[2];
		bool flag = 0;
		bool visit[10000] = { 0 };
		bool exit = 0;

		q[flag].push(A);
		visit[A] = 1;
		int cnt = -1;

		while (!q[flag].empty()) {
			cnt++;
			while (!q[flag].empty()) {
				int i = q[flag].front();
				q[flag].pop();

				if (i == B) {
					exit = 1;
					break;
				}

				for (int k = 0; k < v.size(); k++) {
					if (!visit[v[k]] && check(i, v[k])) {
						//cout << v[k] << endl;
						visit[v[k]] = 1;
						q[!flag].push(v[k]);
					}
				}

			}
			if (exit)
				break;

			flag = !flag;
		}

		if (exit)
			cout << cnt << "\n";
		else
			cout << "Impossible\n";
	}

}