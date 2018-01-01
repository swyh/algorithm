#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;	// 노드의 개수
	cin >> N;

	vector<int> v(N + 1);
	v[1] = -1;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		if (v[a] != 0) {
			v[b] = a;
			continue;
		}
		else if (v[b] != 0) {
			v[a] = b;
			continue;
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << v[i] << '\n';
	}
}