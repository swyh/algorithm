#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int answer = 0;
		cin >> N >> M >> K;

		vector<vector<int>> map(1000, vector<int>(1000));
		vector<vector<int>> going(1000, vector<int>(1000)); // ³öµÑ°÷
		vector<vector<int>> visit(1000, vector<int>(1000)); // ³öµÑ°÷

		vector<int> live(11);
		queue<pair<int, int>> non_activty[2];
		queue<pair<int, int>> activty[2];
		bool flag = 0;

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int ki = i + 500;
				int kj = j + 500;

				cin >> map[ki][kj];

				if (map[ki][kj] > 0) {
					non_activty[flag].push(make_pair(ki, kj));
					visit[ki][kj] = 1;
				}
			}
		}

		int time = 0;
		while (time != K + 1) {
			time++;

			for (int i = 1; i <= 10; i++) {
				if (i != 1)
					live[i - 1] = live[i];
				live[i] = 0;
			}

			while (!activty[flag].empty()) {
				int fi = activty[flag].front().first;
				int fj = activty[flag].front().second;
				activty[flag].pop();
				cnt--;

				live[map[fi][fj]]++;

				for (int k = 0; k < 4; k++) {
					int ki = fi + di[k];
					int kj = fj + dj[k];

					if (visit[ki][kj] == 0 && map[ki][kj] == 0) {
						non_activty[!flag].push(make_pair(ki, kj));
						map[ki][kj] = map[fi][fj];
						visit[ki][kj] = time;
					}
					else if (visit[ki][kj] == time && map[ki][kj] < map[fi][fj])
						map[ki][kj] = map[fi][fj];
				}
			}


			while (!non_activty[flag].empty()) {
				int fi = non_activty[flag].front().first;
				int fj = non_activty[flag].front().second;
				non_activty[flag].pop();

				if (going[fi][fj] == 0) {
					going[fi][fj] = map[fi][fj];
					cnt++;
				}

				going[fi][fj]--;

				if (going[fi][fj] == 0) {
					activty[!flag].push(make_pair(fi, fj));
				}
				else {
					non_activty[!flag].push(make_pair(fi, fj));
				}

			}

			flag = !flag;
		}

		answer = cnt;
		for (int i = 1; i <= 10; i++)
			answer += live[i];

		cout << "#" << t << " " << answer << "\n";
	}

	return 0;
}