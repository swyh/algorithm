#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(vector<bool>& isOpen, vector<vector<int>>& v) {
	int a = 0;
	int b = 0;

	for (int i = 0; i < isOpen.size(); i++) {

		int cost = 0;
		for (int j = 0; j < isOpen.size(); j++) {
			if (i == j)
				continue;
			else if (isOpen[i] == isOpen[j])
				cost += v[i][j];
		}
		if (isOpen[i])
			a += cost;
		else
			b += cost;
	}

	return abs(a - b);
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	vector<bool> isOpen(N / 2);
	vector<bool> temp(N / 2, 1);
	isOpen.insert(isOpen.end(), temp.begin(), temp.end());

	int answer = 0x0fffffff;
	do {
		answer = min(answer, calculate(isOpen, v));
	} while (next_permutation(isOpen.begin(), isOpen.end()));

	cout << answer << endl;
}