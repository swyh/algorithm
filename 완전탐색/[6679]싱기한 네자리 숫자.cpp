#include <iostream>
#include <string>
using namespace std;

string func(int s, int base) {
	string temp = "0123456789ABCDEF";

	if (s == 0)
		return "";
	else
		return func(s / base, base) + temp[s % base];
}

int sum(string s) {
	int temp = 0;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			temp += s[i] - '0';
		else
			temp += s[i] - 'A' + 10;
	}

	return temp;
}

int main() {
	for (int i = 1000; i <= 9999; i++) {
		string a = func(i, 12);
		string b = func(i, 16);

		int a_ = sum(a);
		int b_ = sum(b);
		int i_ = sum(to_string(i));

		if (a_ == b_ && b_ == i_)
			cout << i << endl;
	}
	return 0;
}