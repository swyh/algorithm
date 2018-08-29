#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		map<string, int> m;
		for (int i = 0; i < N; i++) {
			string name, kind;
			cin >> name >> kind;
			m[kind]++;
		}

		int result = 1;
		for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
			result *= iter->second + 1;
		}

		result--;
		cout << result << endl;

	}
}