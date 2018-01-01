#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<int> plus;
	vector<int> minus;
	int one = 0;
	int zero = 0;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (input > 1)
			plus.push_back(input);
		else if (input == 1)
			one++;
		else if (input == 0)
			zero++;
		else if (input < 0)
			minus.push_back(input);
	}

	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	int result = 0;

	for (int i = 0; i < plus.size(); i++) {
		if (plus.size() % 2 == 1 && i == plus.size() - 1)
			result += plus[i];
		else {
			result += plus[i] * plus[i + 1];
			i++;
		}
	}

	for (int i = 0; i < minus.size(); i++) {
		if (minus.size() % 2 == 1 && i == minus.size() - 1) {
			if (zero == 0)
				result += minus[i];
		}
		else {
			result += minus[i] * minus[i + 1];
			i++;
		}
	}

	result += one;

	cout << result << "\n";

	return 0;

}