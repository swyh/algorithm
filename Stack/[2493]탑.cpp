#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int main() {

	int N;
	cin >> N;
	vector<int> heights(N);

	for (int i = 0; i < heights.size(); i++)
		cin >> heights[i];

	vector<int> answer(heights.size());
	stack<pair<int, int>> s;

	for (int i = 0; i < heights.size(); i++) {
		int curr = heights[i];

		if (s.empty());
		else if (s.top().first > curr) {
			answer[i] = s.top().second;
		}
		else if (s.top().first < curr) {
			while (!s.empty() && curr > s.top().first) {
				s.pop();
			}

			if (!s.empty())
				answer[i] = s.top().second;
		}
		s.push(make_pair(curr, i + 1));
	}


	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
		if (i < answer.size() - 1)
			cout << " ";
		else
			cout << "\n";

	}
}