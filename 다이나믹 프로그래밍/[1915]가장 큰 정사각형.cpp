#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>>& board)
{
	int answer = 0;

	vector<vector<int>> dp(board.size(), vector<int>(board[0].size()));

	int max_val = 0;

	for (int i = 0; i < board[0].size(); i++) {
		dp[0][i] = board[0][i];
		max_val = max(max_val, board[0][i]);
	}
	for (int i = 0; i < board.size(); i++) {
		dp[i][0] = board[i][0];
		max_val = max(max_val, board[i][0]);
	}


	for (int i = 1; i < board.size(); i++) {
		for (int j = 1; j < board[i].size(); j++) {
			if (board[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				max_val = max(max_val, dp[i][j]);
			}
		}
	}

	answer = max_val * max_val;

	return answer;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));


	for (int i = 0; i < n; i++) {
		cin.ignore();
		for (int j = 0; j < m; j++) {
			char c;
			cin.get(c);
			board[i][j] = c - '0';
		}
	}

	cout << solution(board) << endl;

}