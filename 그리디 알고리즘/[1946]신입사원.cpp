#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);

		vector<pair<int, int>> v(n);

		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[i] = make_pair(a, b);
		}

		sort(v.begin(), v.end());

		int cnt = 0, cutline = n + 1;
		for (int i = 0; i < n; i++) {
			if (cutline > v[i].second) {
				cutline = v[i].second;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}