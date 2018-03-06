#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int H, W, N;
		cin >> H >> W >> N;
		int Y = 0, X = 0;

		Y = (N % H) == 0 ? H : N % H;
		X = (N - 1) / H;

		cout << Y * 100 + X + 1 << endl;

	}
}