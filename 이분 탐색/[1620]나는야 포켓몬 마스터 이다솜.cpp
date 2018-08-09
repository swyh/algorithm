#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	map<string, int> m;
	int N, M;
	cin >> N >> M;
	vector<string> v;
	vector<string> output;
	v.resize(N + 1);
	output.reserve(M);
	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v[i + 1] = input;
		m[input] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> input;
		if (isdigit(input[0])) {	// string을 int로 바꿔주는 내장 함수
			output.push_back(v[stoi(input)]);
		}
		else
			output.push_back(to_string(m[input]));
	}

	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << "\n";
	}

	return 0;
}