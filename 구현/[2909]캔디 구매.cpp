#include <iostream>
#include <cmath>
using namespace std;

int position(int num, int p) {

	int p_dec = pow(10, p);
	int p_num = (num % p_dec) / pow(10, p - 1);

	return p_num;
}

int main() {
	int C, K;
	volatile int result = 0;
	cin >> C >> K;


	int p = position(C, K);

	result = (C / pow(10, K));
	result *= pow(10, K);
	//cout << "result : " << result << endl;


	if (p >= 5)
		result += pow(10, K);

	cout << result << endl;

	return 0;
}