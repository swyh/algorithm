
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = N;

	while (N--) {

		stack<char> st;

		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {

			if (st.empty()) {
				st.push(s[i]);
			}
			else if (st.top() == 'A' && s[i] == 'A')
				st.pop();
			else if (st.top() == 'B' && s[i] == 'B')
				st.pop();
			else {
				st.push(s[i]);
			}
		}
		if (!st.empty())
			cnt--;
	}

	cout << cnt << endl;
}