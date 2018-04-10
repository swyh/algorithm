#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define SIZE 4	//SIZE를 바꿔서 더 많은 톱니바퀴도 처리할 수 있다.

bool topni[SIZE][8];
bool visit[SIZE] = { 0 };

void rotation(int num, int dire) {	// 돌릴 톱니, 방향(1:시계, -1:반시계)
									//회전
	bool temp[8] = { 0 };
	if (dire == 1) { // 시계
		temp[0] = topni[num][7];
		for (int i = 0; i < 7; i++) {	// right
			temp[i + 1] = topni[num][i];
		}
	}
	else {	// 반시계
		temp[7] = topni[num][0];
		for (int i = 0; i < 7; i++) {	// right
			temp[i] = topni[num][i + 1];
		}
	}

	for (int i = 0; i < 8; i++)
		topni[num][i] = temp[i];
}

void move(int num, int dire) {
	visit[num] = 1;

	int opp_dire = dire == 1 ? -1 : 1;

	if (num != 0 && topni[num][6] != topni[num - 1][2] && visit[num - 1] == 0)
		move(num - 1, opp_dire);
	if (num != SIZE - 1 && topni[num][2] != topni[num + 1][6] && visit[num + 1] == 0)
		move(num + 1, opp_dire);

	rotation(num, dire);
	visit[num] = 0;
}

int main() {

	for (int i = 0; i < SIZE; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++)
			topni[i][j] = s[j] - 48;
	}

	int K;
	cin >> K;

	while (K--) {
		int topni_num, direction;
		cin >> topni_num >> direction;
		move(topni_num - 1, direction);
	}

	int score = 0;
	int bonus = 1;
	for (int i = 0; i < SIZE; i++) {
		if (topni[i][0])
			score += bonus;
		bonus *= 2;
	}
	cout << score << endl;
}