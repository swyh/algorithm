#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string N;
	int B;
	cin >> N >> B;

	long long result = 0;
	for (int i = 0; i < N.size(); i++) {
		int n = 0;
		if (N[i] - '0' < 10)
			n = N[i] - '0';
		else
			n = N[i] + 10 - 'A';
		result += n*pow(B, N.size() - i - 1);
	}
	cout << result << endl;
}