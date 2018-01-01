#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(10);
	vector<int> v2(10);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int input;
		cin >> input;
		sum += input;
		v[i] = sum;
	}
	v[9] = sum;
	sum = 0;
	for (int i = 1; i < 10; i++) {
		int input;
		cin >> input;
		sum += input;
		v2[i] = sum;
	}
	bool win = 0;
	for (int i = 0; i < 9; i++) {
		if (v[i] > v2[i]){
			cout << "Yes" << endl;
			win = 1;
			break;
		}
	}
	if (win == 0)
		cout << "No" << endl;
	return 0;
}