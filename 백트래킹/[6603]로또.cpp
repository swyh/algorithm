#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	while (1) {
		int N;
		cin >> N;
		if (N == 0)
			break;

		vector<int> num(N);
		vector<int> isOpen(6, 1), v_temp(N - 6, 2);
		isOpen.insert(isOpen.end(), v_temp.begin(), v_temp.end());


		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}

		do {
			for (int i = 0; i < N; i++) {
				if (isOpen[i] == 1)
					cout << num[i] << " ";
			}
			cout << endl;
		} while (next_permutation(isOpen.begin(), isOpen.end()));
		cout << endl;
	}

	return 0;
}