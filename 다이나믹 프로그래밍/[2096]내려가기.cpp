#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, max_val = 0, min_val = 999999999;
	cin >> n;

	int input[3] = { 0 };
	int max_prev[3] = { 0 };
	int min_prev[3] = { 0 };
	int max_arr[3] = { 0 };
	int min_arr[3] = { 0 };

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 3; j++) {
			cin >> input[j];
			max_arr[j] = input[j];
			min_arr[j] = 99999999;

			for (int k = 0; k < 3; k++) {
				if (j == 0 && k == 2)
					continue;
				if (j == 2 && k == 0)
					continue;

				max_arr[j] = max(max_arr[j], max_prev[k] + input[j]);
				min_arr[j] = min(min_arr[j], min_prev[k] + input[j]);
			}
		}
		for (int j = 0; j < 3; j++) {
			max_prev[j] = max_arr[j];
			min_prev[j] = min_arr[j];
		}
	}

	for (int i = 0; i < 3; i++) {
		max_val = max(max_val, max_arr[i]);
		min_val = min(min_val, min_arr[i]);
	}
	cout << max_val << " " << min_val << endl;

}