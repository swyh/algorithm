#include <iostream>
#include <string>
using namespace std;

char transform(int n) {
	if (n < 10)
		return n + '0';
	else
		return 'A' + n - 10;
}

int main() {
	int N, B;
	cin >> N >> B;
	string s;
	while (N) {
		s += transform(N % B);
		N /= B;
	}
	for (int i = s.size() - 1; i >= 0; i--)
		cout << s[i];
	cout << endl;
}