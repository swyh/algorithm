#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int min_val = 9999999;

int min_cal(vector<vector<int>>& v, vector<bool>& visit) {
	int sum_true = 0, sum_false = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] == true) {
			for (int j = 0; j < N; j++) {
				if (i != j && visit[j] == true)
					sum_true += v[i][j];
			}
		}
		if (visit[i] == false) {
			for (int j = 0; j < N; j++) {
				if (i != j && visit[j] == false)
					sum_false += v[i][j];
			}
		}

	}
	return abs(sum_true - sum_false);
}

void dfs(int i, int cnt, vector<vector<int>>& v, vector<bool>& visit) {
	if ((N / 2) == cnt) {
		//계산
		min_val = min(min_val, min_cal(v, visit));
	}
	else {	// 팀원이 될 수 있는 모든 조합을 실행한다.
		for (int j = i + 1; j < N; j++) {	// {0 ~ N-1}, {1 ~ N-1}, {2 ~ N-1} , ...
			if (visit[j] == false) {
				visit[j] = true;
				dfs(j, cnt + 1, v, visit);
			}
		}
	}
	if (i != -1)
		visit[i] = false;
}

int fun() {

	vector<vector<int>> v;
	vector<bool> visit;


	cin >> N;
	v.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			v[i].push_back(input);
		}
	}

	dfs(-1, 0, v, visit);
	int temp = min_val;
	min_val = 99999999;

	return temp;

}

int main(void)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " " << fun() << endl;
	}

	return 0; 
}