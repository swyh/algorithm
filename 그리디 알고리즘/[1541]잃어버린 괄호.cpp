#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int result = 0;
	int temp = 0;
	int mul = 1;
	bool c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) {
			temp = temp * 10 + s[i] - '0';
		}
		if (!isdigit(s[i]) || i == s.length() - 1) {
			if (c)
				result -= temp;
			else
				result += temp;
			temp = 0;
			if (s[i] == '-')
				c = 1;
		}
	}
	cout << result << endl;
}