#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {


	FILE *fp;
	fp = fopen("Dataset", "r");
	int input_size = 0;
	int input[1000];
	int num;
	while (1) {
		fscanf(fp, "%d", &input[input_size++]);
		if (feof(fp)) break;
	}
	input_size--;

	fclose(fp);
	for (int i = 0; i < input_size; i++) {
		printf("%d", input[i]);
		if (i != input_size - 1)
			printf(", ");
	}
	printf("\n");
	return 0;
}