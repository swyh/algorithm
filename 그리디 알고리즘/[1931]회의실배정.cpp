#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int begin, end;
		cin >> begin >> end;
		v.push_back(make_pair(end, begin));
	}

	sort(v.begin(), v.end());

	int cnt = 1;
	int temp = v[0].first;
	for (int i = 1; i < n; i++) {
		if (temp <= v[i].second) {
			temp = v[i].first;
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}