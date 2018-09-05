#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sum_digit(const string& a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (isdigit(a[i])) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool comp(const string& a, const string& b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		int a_digit = sum_digit(a);
		int b_digit = sum_digit(b);

		if (a_digit != b_digit)
			return a_digit < b_digit;
		else {
			return a < b;
		}
	}

}

int main() {
	int N;
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++)
		cout << v[i] << "\n";

	return 0;
}