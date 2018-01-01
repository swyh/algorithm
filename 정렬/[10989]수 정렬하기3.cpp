#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> v(10001);
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v[input]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < v[i]; j++)
			cout << i << '\n';
	}
	return 0;
}