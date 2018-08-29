#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool flag = 0;
void brute(string& a, string& b) {
	int i = b.size() - 1;

	if (a.size() == b.size()) {
		if (!b.compare(a))
			flag = 1;
		return;
	}

	char f = b[0];
	char l = b[i];

	string t = b;
	if (l == 'A') {
		t.erase(i);
		brute(a, t);
	}

	if (f == 'B') {
		reverse(b.begin(), b.end());
		b.erase(i);
		brute(a, b);
	}
}
int main() {
	string a, b;
	cin >> a >> b;

	brute(a, b);
	cout << flag << "\n";

	return 0;
}