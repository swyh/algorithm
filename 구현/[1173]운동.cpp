#include <iostream>
using namespace std;

int main() {
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	int hp = m;
	int time = 0;
	int cnt = 0;

	while (N != cnt) {
		if (hp + T <= M) {
			hp += T;
			cnt++;
		}
		else if (hp != m) {
			if (hp - R > m)
				hp -= R;
			else hp = m;
		}
		else
			break;

		time++;
	}

	if (N == cnt)
		cout << time << endl;
	else
		cout << "-1" << endl;
}