#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, rs;
	cin >> s;

	int result = 0;
	int length = s.size() % 3;
	for (int i = 0; i < (3 - length) % 3; i++) {
		s = '0' + s;
	}
	for (int i = 0; i < s.size() + 1; i++) {
		if (i && i % 3 == 0) {
			rs += to_string(result);
			result = 0;
			if (i == s.size() + 1) break;
		}
		result <<= 1;
		result += s[i] - '0';
	}
	cout << rs << endl;
}