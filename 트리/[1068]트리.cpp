#include <iostream>
#include <vector>
using namespace std;

#define ROOT -1

int result = 0;

void traval(int n, int remove, vector<vector<int>>& v) {
	if (n == remove)
		return;

	int leaf = v[n].size();
	for (int i = 0; i < v[n].size(); i++) {
		if (v[n][i] == remove)
			leaf--;
		traval(v[n][i], remove, v);
	}

	if (leaf == 0)
		result++;
}

int main() {
	int N;

	cin >> N;

	vector<vector<int>> v(N);
	int root = 0;

	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent == ROOT) {
			root = i;
			continue;
		}
		v[parent].push_back(i);
	}

	int remove;
	cin >> remove;

	traval(root, remove, v);

	cout << result << endl;

	return 0;
}