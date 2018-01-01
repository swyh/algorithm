#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, sum = 0;
		double result = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {

			double C, G;
			cin >> C >> G;
			sum += C;
			result += C * G;
		}
		cout << fixed;
		cout.precision(1);

		result = roundf((result / (double)sum) * 10) / 10;
		cout << sum << " " << result << endl;
	}
}