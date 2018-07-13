#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void show(int num, int cnt, int vowel, int L, vector<char>& str, vector<char>& v) {
	if (v[num] == 'a' || v[num] == 'e' || v[num] == 'i' ||
		v[num] == 'o' || v[num] == 'u')
		vowel++;


	str[cnt] = v[num];

	if (cnt + 1 == L && vowel >= 1 && L - vowel >= 2) {
		for (int i = 0; i < str.size(); i++)
			cout << str[i];
		cout << "\n";
		return;
	}

	for (int i = num + 1; i < v.size(); i++)
		show(i, cnt + 1, vowel, L, str, v);
}

int main() {
	ios::sync_with_stdio(false);
	int L, C;
	cin >> L >> C;

	vector<char> v(C);
	vector<char> str(L);

	for (int i = 0; i < C; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		show(i, 0, 0, L, str, v);

	return 0;
}