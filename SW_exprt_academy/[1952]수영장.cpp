#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_INT 999999999
int d, m, m3, y;
int start = 0;
int min_val = MAX_INT;

void calculate(int num, int sum, vector<int>& v) { // 1 ~ 12
	if (num > 12)
		return;
	else if (num == 12) {
		sum += min(v[12], m3);
	}
	else if (num == 11) {
		sum += min(v[11] + v[12], m3);
	}
	else {
		sum += min(v[num] + v[num + 1] + v[num + 2], m3);

		for (int i = num + 3; i <= 12; i++) {
			calculate(i, sum, v);
			sum += v[i];
		}
	}

	min_val = min(min_val, sum);
}

int solve() {
	min_val = MAX_INT;

	cin >> d >> m >> m3 >> y;

	vector<int> v(13);

	for (int i = 1; i <= 12; i++) {
		cin >> v[i];

		v[i] = min(v[i] * d, m);
	}

	int result = y;

	int sum = 0;
	for (int i = 1; i <= 12; i++) {
		calculate(i, sum, v);
		sum += v[i];
	}

	result = min(result, min_val);
	return result;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << solve() << "\n";
	}
}