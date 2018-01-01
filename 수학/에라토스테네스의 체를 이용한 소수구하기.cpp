#include <iostream>
using namespace std;

int store[1000001] = { 0 };
int cnt = 0;
bool check[1000001] = { false };

int main() {

	ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;

	for (int i = 2; i <= N; i++) {
		if (check[i] == false) {
			if (i >= M) store[cnt++] = i;
			for (int j = i * 2; j <= N; j += i) {
				check[j] = true;
			}
		}
	}

	for (int i = 0; i < cnt; i++)
		cout << store[i] << "\n";

	return 0;
}