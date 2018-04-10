#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N;
long long max_val = -10000000000, min_val = 10000000000;
vector<int> v;

void DFS(int i, long long value, int plus, int minus, int mul, int div) {
	if (i == N) {
		max_val = max(max_val, value);
		min_val = min(min_val, value);
		return;
	}
	if (plus > 0)
		DFS(i + 1, value + v[i + 1], plus - 1, minus, mul, div);
	if (minus > 0)
		DFS(i + 1, value - v[i + 1], plus, minus - 1, mul, div);
	if (mul > 0)
		DFS(i + 1, value * v[i + 1], plus, minus, mul - 1, div);
	if (div > 0)
		DFS(i + 1, value / v[i + 1], plus, minus, mul, div - 1);

}
int main() {
	cin >> N;

	v.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;

	DFS(1, v[1], plus, minus, mul, div);

	cout << max_val << endl;
	cout << min_val << endl;
}