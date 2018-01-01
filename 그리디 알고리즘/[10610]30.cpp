#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;

	sort(input.begin(), input.end());

	int sum = 0;

	for (int i = 0; i < input.size(); i++) {
		sum += input[i];
	}


	if (input[0] == '0' && sum % 3 == 0) {
		reverse(input.begin(), input.end());
		for (int i = 0; i < input.size(); i++) {
			cout << input[i];
		}
		cout << "\n";
	}
	else
		cout << "-1\n";

	return 0;
}