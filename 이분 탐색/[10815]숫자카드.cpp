#include <stdio.h>
#include <map>

using namespace std;

int main() {
	int c[500000];
	map<int, int> v;
	int N, T;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		v[input]++;
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int input;
		scanf("%d", &input);
		c[i] = v[input];

	}
	for (int i = 0; i < T; i++) {
		printf("%d ", c[i]);
	}

	printf("\n");
}