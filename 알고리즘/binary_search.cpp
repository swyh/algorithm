#include <iostream>
using namespace std;

#define SIZE 500

class Pair {
public:
	int key;
	int value;

	void setPair(int key, int value) {
		this->key = key;
		this->value = value;
	}
};


int bs(int key, Pair arr[], int N) {
	int s = 0;
	int e = N - 1;
	int mid;

	while (s <= e) {
		mid = (s + e) / 2;

		if (arr[mid].key == arr[key].key)
			return arr[mid].value;
		else if (arr[mid].key < arr[key].key)
			s = mid + 1;
		else
			e = mid - 1;
	}

	return -1;
}

int main() {
	int N;
	cin >> N;

	Pair* arr = new Pair[N];

	for (int i = 0; i < N; i++) {
		arr[i].setPair(i, i * 2);
	}

	while (1) {
		int input;
		cin >> input;
		cout << bs(input, arr, N) << endl;
	}

}