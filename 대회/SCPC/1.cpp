#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	int T, test_case;
	cin >> T;
	cin.get();
	for (test_case = 0; test_case < T; test_case++)
	{
		stack<char> s;
		int Answer = 0;
		int cnt = 0;
		int temp = 0;
		while (1) {
			char c = cin.get();
			if (isspace(c)) break;

			if (!s.empty() && ((s.top() == '(' && c == ')') || (s.top() == '{' && c == '}') || (s.top() == '[' && c == ']'))) {
				temp++;
				s.pop();
			}
			else if (c == '(' || c == '[' || c == '{') {
				temp++;
				s.push(c);
			}
			else {
				while (!s.empty()) {
					temp--;
					s.pop();
				}
				cnt = max(temp, cnt);
				Answer = max(Answer, cnt);
				cnt = 0;
				temp = 0;
				continue;
			}

			if (s.empty()) {
				cnt += temp;
				temp = 0;
				Answer = max(Answer, cnt);
			}
		}

		if (!s.empty()) {
			while (!s.empty()) {
				temp--;
				s.pop();
			}
			cnt = max(temp, cnt);
			Answer = max(Answer, cnt);
		}

		cout << "Case #" << test_case + 1 << '\n';
		cout << Answer << '\n';
	}

	return 0;
}