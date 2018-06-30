#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int cost(int i, int j) {
	return abs(i - j);
}

int solve(int N, vector<int> v) {
	int sum = 0;

	for (int i = 1; i < N; i++) {
		sum += cost(v[i - 1], v[i]);
	}

	return sum;
}

int main() {
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int max_ = 0;

	do {
		max_ = max(max_, solve(N, v));
	} while (next_permutation(v.begin(), v.end()));

	cout << max_ << endl;
}