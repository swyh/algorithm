#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;

int main() {
	vector<int> arr(26);
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			arr[s[j] - 'A'] += pow(10, s.size() - 1 - j);
	}

	sort(arr.begin(), arr.end(), greater<>());

	int result = 0;
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 0)
			break;
		result += arr[i] * (9 - i);
	}
	cout << result << endl;
}