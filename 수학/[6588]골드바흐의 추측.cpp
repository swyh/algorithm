#include <cstdio>

int store[1000001] = { 0 };
int cnt = 0;
bool check[1000001] = { false };

int main() {

	for (int i = 2; i <= 1000001; i++) {
		if (check[i] == false) {
			store[cnt++] = i;
			for (int j = i * 2; j <= 1000001; j += i) {
				check[j] = true;
			}
		}
	}

	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 0; i < cnt; i++) {
			if (check[n - store[i]] == false) {
				printf("%d = %d + %d\n", n, store[i], (n - store[i]));
				break;
			}
		}
	}

	return 0;
}