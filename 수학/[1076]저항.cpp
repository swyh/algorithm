#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string arr[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int main() {

	long long result = 0;
	for (int i = 0; i < 3; i++) {
		string a;
		cin >> a;

		int ai;
		for (int j = 0; j < 10; j++) {
			if (arr[j] == a) {
				ai = j;
			}
		}

		if (i == 0)
			result = ai * 10;
		else if (i == 1)
			result += ai;
		else
			result *= pow(10, ai);

	}

	cout << result << endl;
}
