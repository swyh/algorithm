#include <iostream>
using namespace std;

bool mul(int a, int b) {
	for (int i = 1; a * i <= b; i++) {
		if ((b % (a*i)) == 0)
			return 1;
	}
	return 0;
}

int gcd(int a, int b) {
	int max_gcd = 1;
	int range = a;
	for (int i = 1; i <= range; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max_gcd = i;
		}
	}
	return max_gcd;
}

int lcm(int a, int b) {
	int max_gcd = gcd(a, b);
	return max_gcd * a * b;
}

int main() {
	int N, M, result = 0;
	cin >> N >> M;
	N = gcd(N, M);
	if (mul(N, M))
		cout << M - N << endl;
	else
		cout << lcm(N, M) - N << endl;
}