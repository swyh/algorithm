#include <iostream>
using namespace std;

void hanoi(int n, int start, int end) {
	if (n == 0) return;
	hanoi(n - 1, start, 6 - start - end);
	cout << start << " " << end << "\n";
	hanoi(n - 1, 6 - start - end, end);

}

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(n, 1, 3);

	return 0;
}