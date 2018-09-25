
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int arr[100001] = { 0 };
int max_val = 0;
int N;

void calculate(int i, stack<int>& s) {
	while (!s.empty() && (arr[i] < arr[s.top()])) {
		int temp = s.top();
		s.pop();
		if (!s.empty())
			max_val = max(max_val, arr[temp] * (i - s.top() - 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	stack<int> s;

	s.push(-1);

	for (int i = 0; i <= N; i++) {
		calculate(i, s);
		s.push(i);
	}

	cout << max_val << "\n";
}