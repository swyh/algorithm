#include <iostream>
using namespace std;

#define SIZE 5000

int main() {
	int N;
	cin >> N;

	int arr[SIZE] = { 0 };
	int size = 1;
	arr[0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = size - 1; j >= 0; j--) {
			arr[j] *= 2;

			if (arr[j] >= 10) {
				arr[j] %= 10;
				arr[j + 1] += 1;

				if (j == size - 1)
					size++;
			}

		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[size - i - 1];
	}
	cout << endl;
}