#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	vector<int> rank(n, 1);

	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;

		v[i] = make_pair(w, h);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (v[i].first > v[j].first && v[i].second > v[j].second)
				rank[j]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << rank[i] << " ";
	cout << endl;
}