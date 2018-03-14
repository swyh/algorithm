#include <iostream>
#include <string>
#include <vector>
using namespace std;

class String {
private:
	string value;

public:
	bool contain(string s);
	string operator++();
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator >> (istream& is, String& s);

};

bool String::contain(string s) {
	int i = 0;

	for (int j = 0; j < value.length(); j++) {
		if (s[i] == value[j])
			i++;
		else if (i != 0) {
			j -= i;
			i = 0;
		}
		if (i == s.length())
			return 1;
	}

	return 0;
}

string String::operator++() {
	for (int j = 0; j < value.length(); j++) {
		value[j] += 1;
		value[j] = (value[j] % 123 == 0) ? (value[j] % 123) + 97 : value[j];
	}
	return value;
}


ostream& operator<<(ostream& os, const String& s) {
	os << s.value;
	return os;
}

istream& operator >> (istream& is, String& s) {
	is >> s.value;
	return is;
}


int main() {
	int t;
	String s;
	vector<string> v;

	cin >> s >> t;

	for (int i = 0; i < t; i++) {
		string input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (s.contain(v[j])) {
				cout << s << endl;
				return 0;
			}
		}
		++s;
	}
	return 0;
}