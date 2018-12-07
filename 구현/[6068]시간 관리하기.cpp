#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool camp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first > b.first)
		return 1;
	else
		return 0;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		int t, s;
		cin >> t >> s;

		if (t > s) {
			cout << "-1" << endl;
			return 0;
		}

		v[i] = pair<int, int>(s, t);
	}

	sort(v.begin(), v.end(), camp);


	int time = v[0].first;

	for (int i = 0; i < N; i++) {

		if (time > v[i].first)
			time = v[i].first;

		time -= v[i].second;

		if (time <= -1) {
			time = -1;
			break;
		}

	}

	cout << time << endl;

	return 0;
}