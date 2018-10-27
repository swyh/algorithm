#include <iostream>
#include <map>
using namespace std;

int main() {
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	map<int, int> m;

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				m[i + j + k]++;
			}
		}
	}

	int answer = m.begin()->first;

	for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if (m[answer] < iter->second)
			answer = iter->first;
	}

	cout << answer << endl;

	return 0;
}