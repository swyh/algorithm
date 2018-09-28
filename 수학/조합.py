"""
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int d = min(m, n - m);

	unsigned long long answer = 1;
	int temp = d - 1;


	for (int i = n - d + 1; i <= n; i++) {
		answer *= i;
		answer /= (d - temp); // 1 ~ m
		temp--;
	}
	cout << answer << endl;
}"""

n, m = input().split()
n = int(n)
m = int(m)

d = min(m, n - m)
answer = 1

temp = d - 1;
for i in range(n - d + 1, n + 1):
    answer = answer * i // (d - temp);
    temp = temp - 1;

print("%d" % answer)
