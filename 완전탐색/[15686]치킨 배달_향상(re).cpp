#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ZERO	0
#define HOME	1
#define STORE	2

int convolution(vector<pair<int, int>>& home, vector<pair<int, int>>& store,
	vector<bool>& isOpen) {

	int dist_sum = 0;

	for (int i = 0; i < home.size(); i++) {
		int dist = 0x0fffffff;

		for (int j = 0; j < store.size(); j++) {
			if (isOpen[j]) {
				dist = min(dist,
					abs(home[i].first - store[j].first)
					+ abs(home[i].second - store[j].second));
			}
		}
		dist_sum += dist;
	}

	return dist_sum;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> home;
	vector<pair<int, int>> store;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;

			if (input == HOME)
				home.push_back(make_pair(i, j));
			else if (input == STORE)
				store.push_back(make_pair(i, j));
		}
	}

	vector<bool> isOpen(store.size() - M);
	vector<bool> temp(M, 1);
	isOpen.insert(isOpen.end(), temp.begin(), temp.end());

	int answer = 0x0fffffff;
	do {
		answer = min(answer, convolution(home, store, isOpen));
	} while (next_permutation(isOpen.begin(), isOpen.end()));

	cout << answer << endl;
}