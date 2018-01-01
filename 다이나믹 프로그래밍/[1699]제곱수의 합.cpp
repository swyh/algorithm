#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long result = 1;
	for (int i = 1; i <= N; i++) {
		result *= i;
		result = result % 1000000000;
		if (result == 0)
			result = 1;
	}
	cout << result << endl;
	string s = to_string(result);
	int cnt = 0;
	for (int i = s.length() - 1; i > 0; i--) {
		if (s[i] == '0')
			cnt++;
		else
			break;
	}
	cout << cnt << endl;
}