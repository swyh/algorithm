#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int result = 500;

	for (int k = 0; k <= b.size() - a.size(); k++) {
		int temp = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i + k])
				temp++;
		}
		result = min(result, temp);
	}
	cout << result << endl;
}