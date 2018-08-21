#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_val;
int N, M;

inline int diff(int n1, int n2) {
	return abs(n1 - n2);
}

void solve(int num, int cnt, vector<int>& v) {
	if (cnt == 7)
		return;

	int temp = num;
	for (int i = 0; i < v.size(); i++) {
		temp = num * 10 + v[i];
		//cout << temp << endl;
		min_val = min(min_val, diff(temp, N) + cnt);
		solve(temp, cnt + 1, v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;

	min_val = abs(N - 100);
	bool btn[10] = { 0 };
	vector<int> v;

	for (int i = 0; i < M; i++) {
		int non;
		cin >> non;
		btn[non] = 1;
	}

	for (int i = 0; i < 10; i++) {
		if (!btn[i])
			v.push_back(i);
	}

	solve(0, 1, v);

	cout << min_val << "\n";
}