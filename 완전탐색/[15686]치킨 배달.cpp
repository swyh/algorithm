#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> m_locate;	// 전체 건물 위치
vector<pair<int, int>> c_locate;	// M개 선택된 건물 위치
vector<pair<int, int>> p_locate;	// 사람 위치
int result = 9999999;
int N, M;

int sum(int i, int j) {
	int min_ = 9999999;
	for (int k = 0; k < M; k++) {
		min_ = min(min_, abs(i - c_locate[k].first) + abs(j - c_locate[k].second));
	}
	return min_;
}

void complete(int i, int cnt) {
	if (M == cnt) {
		int sum_ = 0;
		for (int j = 0; j < p_locate.size(); j++) {
			sum_ += sum(p_locate[j].first, p_locate[j].second);
		}
		result = min(sum_, result);
		return;
	}

	for (int j = i + 1; j < m_locate.size(); j++) {
		c_locate[cnt] = m_locate[j];
		complete(j, cnt + 1);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input == 2)
				m_locate.push_back(make_pair(i, j));
			else if (input == 1)
				p_locate.push_back(make_pair(i, j));
		}
	}

	c_locate.resize(M);

	for (int i = 0; i < m_locate.size(); i++) {
		c_locate[0] = m_locate[i];
		complete(i, 1);
	}
	cout << result << endl;
}