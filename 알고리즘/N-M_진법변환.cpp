#include <iostream>
#include <string>
#include <cmath>
using namespace std;



//base진수로 변환
string func(int n, int base) {
	string t = "0123456789ABCDEF";

	if (n == 0)
		return "";
	else
		return func(n / base, base) + t[n % base];
}

//base진수 -> 10진수로 변환
int func2(int n, int base) {
	if (n == 0)
		return 0;
	else
		return func2(n / 10, base) * base + (n % 10);
}


int main() {
	int N;
	cin >> N;

	// 3진수를 16진수로 바꾸기!
	int a = func2(N, 3);
	cout << func(a, 16) << endl;

	return 0;
}