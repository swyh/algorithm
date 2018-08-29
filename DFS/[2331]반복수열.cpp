#include <iostream>
#include <cmath>
using namespace std;

int cnt = 0;
int visit[1000000] = { 0 };

void dfs(int num, int P) {
	visit[num]++;

	int q = num, i = 0;
	int sum = 0;

	do {
		i = q % 10;
		q = q / 10;
		sum += pow(i, P);

	} while (q != 0);

	if (visit[sum] < 2)
		dfs(sum, P);

	if (visit[num] == 1)
		cnt++;
}

int main() {
	int A, P;
	cin >> A >> P;

	dfs(A, P);

	cout << cnt << endl;

	return 0;
}