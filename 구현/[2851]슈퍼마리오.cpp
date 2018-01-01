#include <iostream>
using namespace std;

int main() {
	int result = -1;
	int arr[10] = { 0 };

	for (int i = 0; i < 10; i++) {
		int input;
		cin >> input;
		for (int j = i; j < 10; j++) {
			arr[j] += input;
		}
	}

	// 0 ~ 200

	for (int i = 0; i <= 100; i++) {
		for (int j = 9; j >= 0; j--) {
			if (arr[j] == 100 + i) {
				result = arr[j];
				break;
			}
			if (arr[j] == 100 - i) {
				result = arr[j];
				break;
			}
		}
		if (result != -1)
			break;
	}
	cout << result << endl;


}