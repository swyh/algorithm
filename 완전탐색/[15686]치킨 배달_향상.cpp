#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> chicken, house;
#define MAX 9999999999

inline int dist(pair<int, int> &a, pair<int, int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(vector<bool> &isOpen) {
	int sum = 0;
	for (pair<int, int> h : house) {
		int min_val = MAX;
		for (int i = 0; i < chicken.size(); i++) {
			if (isOpen[i] == 1) {
				min_val = min(min_val, dist(h, chicken[i]));
			}
		}
		sum += min_val;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input == 2)
				chicken.push_back(make_pair(i, j));
			else if (input == 1)
				house.push_back(make_pair(i, j));
		}
	}

	int result = MAX;
	vector<bool> isOpen(chicken.size() - M), v_temp(M, 1);	// 뒤에 1을 넣는다. 경우의 수, 조합
	isOpen.insert(isOpen.end(), v_temp.begin(), v_temp.end());
		

	do {
		result = min(result, solve(isOpen));
	} while (next_permutation(isOpen.begin(), isOpen.end()));

	cout << result << endl;
}