#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N;
long long max_val = -10000000000, min_val = 10000000000;


void DFS(int i, long long value, int plus, int minus, int mul, int div, vector<int>& v) {
	if (i == N) {
		max_val = max(max_val, value);
		min_val = min(min_val, value);
		return;
	}
	if (plus > 0)
		DFS(i + 1, value + v[i + 1], plus - 1, minus, mul, div, v);
	if (minus > 0)
		DFS(i + 1, value - v[i + 1], plus, minus - 1, mul, div, v);
	if (mul > 0)
		DFS(i + 1, value * v[i + 1], plus, minus, mul - 1, div, v);
	if (div > 0)
		DFS(i + 1, value / v[i + 1], plus, minus, mul, div - 1, v);

}
int foo() {
	cin >> N;
	vector<int> v;
	v.resize(N + 1);



	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	DFS(1, v[1], plus, minus, mul, div, v);

	return max_val - min_val;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " " << foo() << endl;
		max_val = -10000000000, min_val = 10000000000;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}