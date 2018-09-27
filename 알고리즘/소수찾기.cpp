#include <iostream>
using namespace std;


// N까지의 소수 찾기
void prime_all(int N) {
	bool* arr = new bool[N + 1]{ 0 };

	for (int i = 2; i*i <= N; i++) {
		if (arr[i] == 0) {
			for (int j = i + i; j <= N; j = j + i) {
				arr[j] = 1;
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		if (arr[i] == 0)
			cout << i << ", ";
	}
	cout << endl;
}

int prime(int N) {
	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int N;
	cin >> N;

	prime_all(N);

	cout << "이것은 ";
	cout << prime(N) << endl;
}