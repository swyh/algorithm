#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N1, N2;
	cin >> N1 >> N2;

	string S1, S2;
	cin >> S1 >> S2;

	reverse(S1.begin(), S1.end());

	int T;
	cin >> T;

	string answer = "";

	int i = 0;
	int j = 0;
	int n = S1.size();

	while (1) {
		if (i >= S1.size()) {
			for (int k = j; k < S2.size(); k++) {
				answer += S2[k];
			}
			break;
		}
		else if (j >= S2.size()) {
			for (int k = i; k < S1.size(); k++) {
				answer += S1[k];
			}
			break;
		}

		if (n > T) {
			answer += S1[i];
			i++;
			n--;
		}
		else {
			answer += S2[j];
			j++;
			T--;
		}

	}

	cout << answer << endl;
}