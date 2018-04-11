#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N; // 보드의 크기(1 <= N <= 20)
int max_ = 0;

// direction : 아래, 위, 오, 왼 (0,1,2,3) 밀기
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

void print(vector<vector<int>>& v) {
	cout << "print" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check(int i, int j) {
	if (i < 1 || j < 1 || N < i || N < j)
		return 0;
	else
		return 1;
}

void move(int i, int j, int dire, vector<vector<int>>& v, vector<vector<bool>>& merge_v) {
	int ki = i + di[dire];
	int kj = j + dj[dire];

	if (check(ki, kj) && v[ki][kj] == 0) {
		//cout << "move ";
		//print(v);
		v[ki][kj] = v[i][j];
		v[i][j] = 0;
		move(ki, kj, dire, v, merge_v);
	}
	else if (check(ki, kj) && v[ki][kj] == v[i][j] && merge_v[ki][kj] == false) {
		v[ki][kj] *= 2;
		v[i][j] = 0;
		merge_v[ki][kj] = true;
		max_ = max(max_, v[ki][kj]);
		//cout << "merge ";
		//print(v);
	}
}

void push(int dire, vector<vector<int>>& v, vector<vector<bool>> merge_v) {	//밀기(파라미터 : 방향)

	for (int i = 1; i <= N; i++) {	// 각 인덱스에 대해 민다.
		for (int j = 1; j <= N; j++) {

			int x, y;
			//아래 위 오른쪽 왼쪽  0 1 2 3 
			if (dire == 0) {	// 아래
				x = N + 1 - i;
				y = j;
			}
			else if (dire == 1) {	// 위
				x = i;
				y = j;
			}
			else if (dire == 2) {	// 오른쪽
				x = j;
				y = N + 1 - i;
			}
			else { // 왼쪽
				x = j;
				y = i;
			}

			if (v[x][y] == 0)
				continue;

			move(x, y, dire, v, merge_v);
		}
	}
}

void brute(int direction, int cnt, vector<vector<int>> v, vector<vector<bool>> merge_v) {	//완전탐색(횟수/최대5번)

	push(direction, v, merge_v);

	for (int i = 0; i < 4; i++) {
		if (cnt < 5)
			brute(i, cnt + 1, v, merge_v);
	}
}

int main() {
	cin >> N;

	vector<vector<int>> v(N + 1);
	vector<vector<bool>> merge_v(N + 1);

	for (int i = 1; i <= N; i++) {
		v[i].resize(N + 1);
		merge_v[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
			max_ = max(max_, v[i][j]);
		}
	}

	for (int i = 0; i < 4; i++) {
		brute(i, 1, v, merge_v);
	}

	cout << max_ << endl;

}