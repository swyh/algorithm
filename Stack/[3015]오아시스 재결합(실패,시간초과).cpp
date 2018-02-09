#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> o, s;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		o.push(input);
	}




	if (N == 1)
		cout << "0" << endl;
	else if (N == 2)
		cout << "1" << endl;
	else {
		int cnt = 0;

		while (!o.empty()) {
			int max = 0;
			int x = o.top();
			o.pop();

			s = o;

			while (!s.empty()) {
				if (s.top() >= max) {
					max = s.top();
					s.pop();
					cnt++;
				}
				else
					s.pop();
				if (max > x)
					break;
			}
		}

		cout << cnt << endl;
	}
}