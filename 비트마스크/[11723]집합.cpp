#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {


	int M, value = 0;
	scanf("%d", &M);

	int input;
	char s[10] = { '\0' };

	while (M--) {

		scanf("%s", s);
		if (!strcmp(s, "add")) {
			scanf("%d", &input);
			value |= 0x01 << input;
		}
		else if (!strcmp(s, "remove")) {
			scanf("%d", &input);
			value &= ~(0x01 << input);
		}
		else if (!strcmp(s, "check")) {
			scanf("%d", &input);
			if (value & (0x01 << input))
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(s, "toggle")) {
			scanf("%d", &input);
			if (value & (0x01 << input))
				value &= ~(0x01 << input);
			else
				value |= 0x01 << input;
		}
		else if (!strcmp(s, "all"))
			value |= 0xffffffff;
		else if (!strcmp(s, "empty"))
			value = 0;

	}
}