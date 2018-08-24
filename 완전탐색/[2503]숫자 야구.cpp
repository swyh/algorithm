#include <iostream>
#include <vector>
using namespace std;

class base_set {
public:
	int q;
	int s;
	int b;

	base_set(int q, int s, int b) {
		this->q = q;
		this->s = s;
		this->b = b;
	}
};

pair<int, int> compare(int x, int y) {
	int s = 0;
	int b = 0;
	int xt[3] = { x / 100, (x % 100) / 10, x % 10 };
	int yt[3] = { y / 100, (y % 100) / 10, y % 10 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (xt[i] == yt[j]) {
				if (i == j)
					s++;
				else
					b++;
			}
		}
	}
	return make_pair(s, b);
}

bool check(int n, vector<base_set>& v) {
	for (int i = 0; i < v.size(); i++) {
		pair<int, int> p = compare(n, v[i].q);

		if (p.first != v[i].s || p.second != v[i].b)
			return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<base_set> v;

	for (int i = 0; i < N; i++) {
		int q, s, b;
		cin >> q >> s >> b;
		v.push_back(base_set(q, s, b));
	}

	int cnt = 0;
	for (int i = 111; i < 1000; i++) {
		int it[3] = { i / 100, (i % 100) / 10, i % 10 };

		if (it[0] == it[1] || it[0] == it[2] || it[1] == it[2])
			continue;
		if (it[0] == 0 || it[1] == 0 || it[2] == 0)
			continue;

		cnt += check(i, v);
	}

	cout << cnt << "\n";

	return 0;

}