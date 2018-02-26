#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	const int ARR_MAX = 1200000;
	unsigned input, visit[ARR_MAX] = { 0 };

	while (~scanf("%u", &input)) {
		if (visit[input / 32] & (1 << input % 32))	// 이미 방문했다면
			continue;

		printf("%u ", input);
		visit[input / 32] |= (1 << input % 32);
	}
	printf("\n");
}