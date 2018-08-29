#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int i = b.size() - 1;
	while (1) {
		if (a.size() == b.size()) {
			if (!b.compare(a))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;
		}

		char c = b[i];
		b.erase(i--);
		if (c == 'B')
			reverse(b.begin(), b.end());
	}

	return 0;
}