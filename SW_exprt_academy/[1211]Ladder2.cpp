#include <iostream>
#include <vector>
using namespace std;


bool check(int i, int j) {
	if (i < 0 || j < 0 || i > 99 || j > 99)
		return 0;
	else
		return 1;
}

class Ladder {
public:
	int i, j;
	int cnt;
	vector<vector<int>> v;

	Ladder() : cnt(0) {
		v.resize(100);
	};

	int move(int i, int j);
	void down();
	void right();
	void left();
};

int Ladder::move(int i, int j) {
	this->i = i;
	this->j = j;

	down();

	int temp = cnt;
	cnt = 0;
	return temp;
}

void Ladder::down() {
	while (i < 99) {
		right();
		left();
		if ((check(i, j + 1) && v[i][j + 1]) || (check(i, j - 1) && v[i][j - 1]))
			continue;
		if (check(i + 1, j) && v[i + 1][j]) {
			i++;
			cnt++;
		}

	}
}

void Ladder::right() {
	if (check(i, j + 1) && v[i][j + 1]) {
		while (check(i, j + 1) && v[i][j + 1]) {
			++j;
			cnt++;
		}
		i++;
		cnt++;
	}
}

void Ladder::left() {
	if (check(i, j - 1) && v[i][j - 1]) {
		while (check(i, j - 1) && v[i][j - 1]) {
			--j;
			cnt++;
		}

		i++;
		cnt++;
	}
}


int main() {
	ios::sync_with_stdio(false);

	int T = 10;
	Ladder ladder[10];

	while (T--) {
		int num;
		cin >> num;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int input;
				cin >> input;
				ladder[T].v[i].push_back(input);
			}
		}

		int min_cnt = 1000000;
		int min_j = 0;
		for (int j = 0; j < 100; j++) {
			if (ladder[T].v[0][j] == 0)
				continue;
			int temp = ladder[T].move(0, j);
			if (min_cnt > temp) {
				min_cnt = temp;
				min_j = j;
			}
		}
		cout << "#" << num << " " << min_j << endl;
	}
}