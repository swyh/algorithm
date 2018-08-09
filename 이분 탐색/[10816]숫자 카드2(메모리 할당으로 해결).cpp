#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	float v[20000002] = { 0 };
	int N, T;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		v[input + 10000001]++;
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int input;
		scanf("%d", &input);
		printf("%d ", (int)v[input + 10000001]);
	}

	printf("\n");
}