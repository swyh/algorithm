
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int result = 0;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			int input;
			cin >> v[i];
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				result += gcd(v[i], v[j]);
			}
		}
		cout << result << endl;

	}
	return 0;
}