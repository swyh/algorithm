#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {

		string s;
		int alphabet[30] = { 0 };
		bool succ = 1;

		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			alphabet[s[i] - 'A']++;

			if (alphabet[s[i] - 'A'] == 3) {
				if (i + 1 < s.length() && s[i] == s[i + 1]) {
					alphabet[s[i] - 'A'] = 0;
					i++;
				}
				else {
					cout << "FAKE" << endl;
					succ = 0;
					break;
				}
			}
		}

		if (succ)
			cout << "OK" << endl;
	}

	return 0;
}