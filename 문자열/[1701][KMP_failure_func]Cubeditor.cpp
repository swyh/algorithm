
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_val = 0;

void failureFunction(string& P) {
	vector<int> F(P.size());	// failure function
	F[0] = 0;
	int i = 1;	// text index
	int j = 0;	// pattern index
	int m = P.size();

	while (i < m) {
		if (P[i] == P[j]) {	// match text and pattern 
			F[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) // miss match
			j = F[j - 1];
		else { // j == 0
			F[i] = 0;
			i++;
		}
	}
	int max_temp = 0;
	for (int i = 0; i < F.size(); i++)
		max_temp = max(max_temp, F[i]);

	max_val = max(max_temp, max_val);
}

int main() {
	string P;

	cin >> P;

	for (int i = 0; i < P.size(); i++) {
		string str = P.substr(i, P.size());
		failureFunction(str);
	}

	cout << max_val << endl;

	return 0;
}