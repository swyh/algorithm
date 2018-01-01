#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class people {
public:
	int a, b, c;
	string name;

	people(string name, int a, int b, int c) {
		this->name = name;
		this->a = a;
		this->b = b;
		this->c = c;
	}

};

bool operator < (people& left, people& right) {
	if (left.a > right.a)
		return 1;
	else if (left.a < right.a)
		return 0;
	else {
		if (left.b > right.b)
			return 0;
		else if (left.b < right.b)
			return 1;
		else {
			if (left.c > right.c)
				return 1;
			else if (left.c < right.c)
				return 0;
			else {
				if (left.name < right.name)
					return 1;
				else
					return 0;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<people> v;

	for (int i = 0; i < N; i++) {
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		v.push_back(people(name, a, b, c));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i].name << "\n";
	}

	return 0;
}