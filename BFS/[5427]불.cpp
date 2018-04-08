#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int w, h;
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

//vector를 출력한다.
void print(vector<vector<char>>& v) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << v[i][j];
		cout << endl;
	}
}

//vector의 잘못된 index를 참조하는지 확인하는 함수
bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= h || j >= w)
		return 0;
	else
		return 1;
}

int BFS(vector<vector<char>>& v, vector<pair<int, int>>& fire, pair<int, int> start) {
	queue<pair<int, int>> q[2];			// 상근이의 위치인덱스를 저장
	queue<pair<int, int>> q_fire[2];	// 불의 위치인덱스를 저장
										// queue를 2개를 생성하여 0,1 인덱스를 번갈아가며 다음 이동할 위치인덱스를 저장한다.
	bool idx = 0;	// queue를 0,1 번갈아가며 사용하기 위한 변수
	int sec = 0;


	q[idx].push(start);
	for (int i = 0; i < fire.size(); i++)
		q_fire[idx].push(fire[i]);


	while (1) {
		//1초가 지났음을 의미(한칸씩 이동)
		sec++;

		//상근이 이동
		while (!q[idx].empty()) {
			int fi = q[idx].front().first;
			int fj = q[idx].front().second;
			q[idx].pop();

			// 불이 옮겨붙었을 경우
			if (v[fi][fj] == '*')
				continue;

			// 동서남북으로 이동할 수 있는지 확인
			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				//상근이가 이동할 수 있는 위치
				if (check(ki, kj) && v[ki][kj] == '.') {
					v[ki][kj] = '@';
					q[!idx].push(make_pair(ki, kj));
				}
				else if (!check(ki, kj))	// 상근이가 외부로 탈출
					return sec;
			}
		}

		if (q[!idx].empty())	// 더 이상 갈 곳이 없을때
			return 0;

		//불의 이동
		while (!q_fire[idx].empty()) {
			int fi = q_fire[idx].front().first;
			int fj = q_fire[idx].front().second;
			q_fire[idx].pop();

			// 동서남북으로 이동할 수 있는지 확인
			for (int k = 0; k < 4; k++) {
				int ki = fi + di[k];
				int kj = fj + dj[k];

				//불이 이동할 수 있는 위치
				if (check(ki, kj) && (v[ki][kj] == '.' || v[ki][kj] == '@')) {
					v[ki][kj] = '*';
					q_fire[!idx].push(make_pair(ki, kj));
				}
			}
		}

		//index를 뒤집는다.
		idx = !idx;
	}
}


int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> w >> h;
		cin.ignore();

		vector<vector<char>> v(h);

		//fire와 start 지점의 인덱스를 저장하는 벡터와 변수
		vector<pair<int, int>> fire;
		pair<int, int> start;

		for (int i = 0; i < h; i++) {
			string s;
			getline(cin, s);

			//get and store input
			for (int j = 0; j < s.size(); j++) {
				v[i].push_back(s[j]);
				if (s[j] == '*') //it's fire
					fire.push_back(make_pair(i, j));
				else if (s[j] == '@')
					start = make_pair(i, j);
			}
		}

		int result = BFS(v, fire, start);

		if (result)
			cout << result << endl;
		else
			cout << "IMPOSSIBLE" << endl; \
	}
}