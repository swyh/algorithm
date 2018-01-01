#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(make_pair(s.size(), s));
	}
	sort(v.begin(), v.end());
	vector<pair<int, string>>::iterator iter = unique(v.begin(), v.end());
	for (vector<pair<int, string>>::iterator iter2 = v.begin(); iter2 != iter; iter2++) {
		cout << iter2->second << endl;
	}
}