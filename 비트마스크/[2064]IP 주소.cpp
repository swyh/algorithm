#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <cmath>

unsigned int inet_addr(char *IP_ADDR) {
	unsigned int ret = 0;
	char *oct;
	for (int i = 3; i >= 0; i--) {
		oct = strtok(IP_ADDR, ".");
		ret += atoi(oct) << (8 * i);
		IP_ADDR = NULL;
	}
	return ret;
}

void inet_ntoa(unsigned int ip) {
	unsigned char byte[4];
	byte[0] = ip & 0xff;
	byte[1] = (ip >> 8) & 0xff;
	byte[2] = (ip >> 16) & 0xff;
	byte[3] = (ip >> 24) & 0xff;

	printf("%u.%u.%u.%u\n", byte[3], byte[2], byte[1], byte[0]);
}

int main() {
	int N;
	scanf("%d", &N);

	char s[30];
	unsigned int min = 0xffffffff, max = 0, net = 0, mask = 0;

	for (int i = 0; i < N; i++) {
		scanf("%s", s);

		unsigned input = inet_addr(s);
		min &= input;
		max |= input;
	}

	unsigned int cnt = max - min;

	for (int i = 31; i >= 0; i--) {	// mask
		if (((cnt >> i) & 0x01) == 1)
			break;

		net |= min & (1 << i);
	}

	for (int i = 31; i >= 0; i--) {	// mask
		if (((cnt >> i) & 0x01) == 1)
			break;

		mask |= (1 << i);
	}

	inet_ntoa(net);
	inet_ntoa(mask);
}