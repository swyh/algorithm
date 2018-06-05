#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> q;	// value, index
		priority_queue<int> pq;	// max_value

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			q.push(make_pair(input, i));
			pq.push(input);
		}

		int cnt = 1;

		while (true) {

			pair<int, int> iter = q.front();
			q.pop();

			if (iter.first < pq.top()) {	// 값이 더 클때
				q.push(iter);	// 맨뒤에 삽입
			}
			else if (iter.first == pq.top()) {	// 값이 같을 때
				if (iter.second == m)
					break;
				else {
					pq.pop();
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}