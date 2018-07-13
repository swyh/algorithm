#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;	// train 수, 명령 수

	vector<unsigned int> v(N + 1);

	for (int i = 0; i < M; i++) {
		int oper;
		cin >> oper;

		if (oper == 1 || oper == 2) {
			int train, position;	// 1 <= position <= 20
			cin >> train >> position;

			if (oper == 1)
				v[train] |= 1 << (position - 1);
			else
				v[train] &= ~(1 << (position - 1));
		}
		else {
			int train;
			cin >> train;

			if (oper == 3)
				v[train] = (v[train] << 1) & 0xfffff;
			else
				v[train] = v[train] >> 1;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (v[i] == 0xffffffff)
			continue;

		cnt++;

		for (int j = i + 1; j <= N; j++) {
			if (v[i] == v[j])
				v[j] = 0xffffffff;
		}
	}
	cout << cnt << endl;
}