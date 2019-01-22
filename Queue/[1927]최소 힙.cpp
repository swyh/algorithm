#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int main() {


	int N, input;
	priority_queue<int> q;

	scanf("%d", &N);

	while (N--) {
		scanf("%d", &input);

		if (input)
			q.push(-input);
		else if (q.empty())
			printf("0\n");
		else {
			printf("%d\n", -q.top());
			q.pop();
		}
	}

	return 0;
}