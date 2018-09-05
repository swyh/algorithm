#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string& a, const string& b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a < b;
}

int main() {
	int N;
	cin >> N;
	ios::sync_with_stdio(false);

	vector<string> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			if (isdigit(s[j])) {
				string t;
				bool start = 0;
				int k = 0;

				while (j + k < s.size()) {
					if (start == 0 && s[j + k] == '0') {
						k++;
						continue;
					}
					else if (isdigit(s[j + k])) {
						t += s[j + k];
						start = 1;
					}
					else
						break;
					k++;
				}

				if (start == 0 && t.size() == 0)
					v.push_back("0");
				else
					v.push_back(t);

				j += k;
			}
		}
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}