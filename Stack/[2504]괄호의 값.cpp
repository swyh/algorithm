#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	int err = 0, cnt = 0, result = 0;
	cin >> s;

	stack<pair<char, char>> stack;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '(' || s[i] == '[') {
			stack.push(make_pair(s[i], '+'));
		}
		else if (stack.top().first == '(' && s[i] == ')') {
			if (stack.top().second == '+')
				cnt += 2;
			else
				cnt *= 2;

			stack.pop();

			if (!stack.empty())
				stack.top().second = '*';
			else {
				result += cnt;
				cnt = 0;
			}

		}
		else if (stack.top().first == '[' && s[i] == ']') {
			if (stack.top().second == '+')
				cnt += 3;
			else
				cnt *= 3;

			stack.pop();

			if (!stack.empty())
				stack.top().second = '*';
			else {
				result += cnt;
				cnt = 0;
			}
		}
		else {
			cout << "err : " << i << " : " << s[i] << endl;
			err = 1;
			break;
		}
	}


	if (!stack.empty() || err)
		cout << 0 << endl;
	else {
		cout << result << endl;
	}
}
