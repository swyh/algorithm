#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int N, M, m = 0;
	vector<int> v;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (v[i] + v[j] + v[k] <= M)
					m = max(m, (v[i] + v[j] + v[k]));
			}
		}
	}
	cout << m << endl;

}