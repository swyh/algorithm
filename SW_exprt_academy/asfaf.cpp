#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

#define MAX_INT 9999999
int min_val = MAX_INT;

inline int dist(pair<int, int>& a, pair<int, int>&b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int move(vector<pair<int, int>>& p, pair<int, int>& c, int& c_val) {
	if (p.size() == 0)
		return 0;

	priority_queue<int> pq;
	int p_size = p.size();

	for (int i = 0; i < p.size(); i++) {
		pq.push(-dist(p[i], c));
	}

	int time = 0;
	int complete = 0;
	int wait = 0;
	list<int> running;

	while (1) {
		while (wait > 0 && running.size() < 3) { // 내려갈 준비
			running.push_back(c_val);
			wait--;
		}

		list<int>::iterator iter = running.begin();

		while (iter != running.end()) {	// 한칸씩 내려감
			*iter = (*iter) - 1;

			if (*iter == 0) {
				iter = running.erase(iter);
				complete++;

				if (complete == p_size)
					return time + 1;
			}
			else
				iter++;
		}

		while (!pq.empty() && -pq.top() == time) {	// 도착
			pq.pop();
			wait++;
		}

		time++;
	}
}

void mask(int num, vector<bool>& select, vector<pair<int, int>>& p, vector<pair<int, int>>& c, vector<int>& c_val) {
	if (num == select.size()) {
		vector<pair<int, int>> a;
		vector<pair<int, int>> b;

		for (int i = 0; i < select.size(); i++) {
			if (select[i])
				a.push_back(p[i]);
			else
				b.push_back(p[i]);
		}

		int max_val = max(move(a, c[0], c_val[0]), move(b, c[1], c_val[1]));
		min_val = min(min_val, max_val);

		return;
	}

	mask(num + 1, select, p, c, c_val);
	select[num] = 1;
	mask(num + 1, select, p, c, c_val);
	select[num] = 0;
}

int solve() {
	min_val = MAX_INT;

	int N;
	cin >> N;

	vector<pair<int, int>> p;
	vector<pair<int, int>> c;
	vector<int> c_val;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;

			if (input == 1)
				p.push_back(make_pair(i, j));
			else if (input > 1) {
				c.push_back(make_pair(i, j));
				c_val.push_back(input);
			}
		}
	}

	vector<bool> select(p.size());

	mask(0, select, p, c, c_val);

	return min_val;

}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << solve() << "\n";
	}
}