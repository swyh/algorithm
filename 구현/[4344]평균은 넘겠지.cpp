#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		vector<int> v;
		double num, avg = 0, cnt = 0, result = 0;
		cin >> num;

		for (int i = 0; i < num; i++) {
			int input;
			cin >> input;
			avg += input;
			v.push_back(input);
		}
		avg /= num;
		for (int i = 0; i < num; i++) {
			if (v[i] > avg)
				cnt++;
		}
		result = cnt / num * 100;

		cout << fixed;
		cout.precision(3);
		cout << round(result * 1000) / 1000 << "%" << endl;
	}
}