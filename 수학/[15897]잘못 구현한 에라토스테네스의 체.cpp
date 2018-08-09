#include <iostream>
#include <cmath>
using namespace std;

double n;

long long search(int start, int end) {
	int s_val = (int)ceil((double)(n / start));
	int e_val = (int)ceil((double)(n / end));

	int mid = (start + end) / 2;
	long long cnt = 0;


	if (s_val == e_val)
		return s_val * (end - start + 1);
	else {
		cnt += search(start, mid);
		cnt += search(mid + 1, end);
		return cnt;
	}
}

long long answer() {
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j += i) {
			cnt++;
		}
	}
	return cnt;
}

long long answer2() {
	long long cnt = 0;
	for (double i = 1; i <= n; i++) {
		cnt += (int)ceil((double)(n / i));
	}
	return cnt;
}

int main() {
	cin >> n;
	long long cnt = 0;

	for (double i = 1; i < ceil(sqrt(n)); i++) {
		cnt += ceil((double)(n / i));
	}

	cnt += search(ceil(sqrt(n)), n);

	cout << cnt << endl;
	//cout << answer2() << endl;
	//cout << answer() << endl;
}