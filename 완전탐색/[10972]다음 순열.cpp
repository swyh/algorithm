#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	vector<int> d(N);

	for (int i = 0; i < N; i++) {
		int input;
		cin >> v[i];
		d[i] = v[i];
	}

	sort(d.begin(), d.end(), greater<int>());
	bool check = 0;

	for (int i = 0; i < N; i++) {
		if (v[i] != d[i]) {
			check = 1;
			break;
		}
	}

	if (check) {
		next_permutation(v.begin(), v.end());
		for (int i = 0; i < N; i++)
			cout << v[i] << " ";
	}
	else
		cout << "-1";
	cout << endl;

	return 0;
}