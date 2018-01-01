#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int A, B, m;
	cin >> A >> B >> m;

	long long result = 0;

	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		result += n*pow(A, m - i - 1);
	}
	vector<int> rs;
	while (result) {	//result 0 될때까지
		rs.push_back(result % B);
		result /= B;
	}

	for (vector<int>::reverse_iterator iter = rs.rbegin(); iter != rs.rend(); iter++)
		cout << *iter << " ";

	cout << endl;
	return 0;
}