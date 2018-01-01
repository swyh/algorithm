#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	set<string> m;
	while (n--) {
		string s, comend;
		cin >> s>> comend;
		if (comend == "enter")
			m.insert(s);
		else
			m.erase(s);
	}
	for (set<string>::reverse_iterator iter = m.rbegin(); iter != m.rend(); iter++) {
		cout << *iter << "\n";
	}
	return 0;
}