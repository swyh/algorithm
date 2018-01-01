#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<vector<string>> v(201);

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		v[age].push_back(name);
	}

	for (int i = 0; i < 201; i++) {
		if (!v[i].empty()) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << i << " " << v[i][j] << '\n';
			}
		}
	}
	return 0;
}