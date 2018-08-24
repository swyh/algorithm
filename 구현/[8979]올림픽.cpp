#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class medal {
public:
	int g;
	int s;
	int b;

	medal() {}

	medal(int g, int s, int b) {
		this->g = g;
		this->s = s;
		this->b = b;
	}

	void setMedal(int g, int s, int b) {
		this->g = g;
		this->s = s;
		this->b = b;
	}
};

bool operator<(const medal &a, const medal &b) {
	if (a.g > b.g)
		return 1;
	else if (a.g < b.g)
		return 0;
	else {
		if (a.s > b.s)
			return 1;
		else if (a.s < b.s)
			return 0;
		else
			return a.b > b.b;
	}
}

bool compare(const medal &a, const medal &b) {
	if (a.g == b.g && a.s == b.s && a.b == b.b)
		return 1;
	else
		return 0;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<medal> v;
	medal answer;

	for (int i = 0; i < N; i++) {
		int n, g, s, b;
		cin >> n >> g >> s >> b;

		if (K == n)
			answer.setMedal(g, s, b);

		v.push_back(medal(g, s, b));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (compare(v[i], answer)) {
			cout << i + 1 << endl;
			break;
		}
	}
}