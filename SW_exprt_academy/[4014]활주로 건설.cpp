#include <iostream>
#include <vector>
using namespace std;

bool isCheck(vector<int>& v, int X) {
	vector<bool> wall(v.size());

	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] == v[i])
			continue;
		else if (v[i - 1] + 1 == v[i]) {    // 오르막길
			for (int x = 1; x <= X; x++) {
				if (i - x == -1 || wall[i - x] == 1 || v[i - x] + 1 != v[i])
					return 0;
				else
					wall[i - x] = 1;
			}
		}
		else if (v[i - 1] == v[i] + 1) {    // 내리막길
			for (int x = 0; x < X; x++) {
				if (i + x == v.size() || wall[i + x] == 1 || v[i - 1] != v[i + x] + 1)
					return 0;
				else
					wall[i + x] = 1;
			}
			i += X - 1;
		}
		else
			return 0;
	}

	return 1;
}

int foo() {
	int N, X;
	int result = 0;

	cin >> N >> X;

	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		result += isCheck(v[i], X);
	}

	for (int j = 0; j < N; j++) {
		vector<int> temp;
		for (int i = 0; i < N; i++) {
			temp.push_back(v[i][j]);
		}
		result += isCheck(temp, X);
	}

	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " " << foo() << endl;
	}
	return 0;
}