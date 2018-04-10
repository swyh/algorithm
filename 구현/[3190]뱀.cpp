#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FREE	0
#define APPLE	1
#define SNAKE	2

#define UP		0
#define RIGHT	1
#define DOWN	2
#define LEFT	3

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };


vector<vector<int>> v;	// map
queue <pair<int, char>> direction;	// 방향전환
queue<pair<int, int>> snake;	// 뱀의 위치 index가 담겨있음
int currentDir = RIGHT;// 현재 방향
int sec = 0;


bool check(int i, int j, int N) {	// 뱀이 벽에 붙딪쳤는지 확인
	if (i < 1 || j < 1 || i > N || j > N)
		return 1;
	else
		return 0;
}

void move(int N) {
	while (++sec) {
		// 다음 이동할 위치
		int move_i = snake.back().first + di[currentDir];
		int move_j = snake.back().second + dj[currentDir];

		// 내 자신을 만나거나, 벽을 만난경우 종료
		if (check(move_i, move_j, N) || v[move_i][move_j] == SNAKE) {
			break;
		}

		if (v[move_i][move_j] != APPLE) {	// 사과가 없으면 꼬리 삭제
			int tail_i = snake.front().first;
			int tail_j = snake.front().second;
			v[tail_i][tail_j] = FREE;
			snake.pop();
		}

		// 이동한 곳을 뱀 queue에 넣는다.
		snake.push(make_pair(move_i, move_j));
		v[move_i][move_j] = SNAKE;

		// 방향을 바꾼다.
		if (!direction.empty()) {
			int dir_time = direction.front().first;

			if (dir_time == sec) {	// 방향변경
				int dir = direction.front().second;
				direction.pop();

				if (dir == 'L') {	// 왼쪽으로
					currentDir = (currentDir - 1) < 0 ? 3 : (currentDir - 1);
				}
				else {	// 오른쪽으로
					currentDir = (currentDir + 1) % 4;
				}
			}
		}
	}
}

int main() {
	int N, K;	// map의 size, K개의 사과가 주어진다.
	cin >> N >> K;

	v.resize(N + 1);	// 0번 index는 사용하지 않는다.
	for (int i = 1; i <= N; i++)
		v[i].resize(N + 1);
	v[1][1] = SNAKE;

	while (K--) {
		int i, j;
		cin >> i >> j;
		v[i][j] = APPLE;
	}

	int L;	// 방향 변환의 개수
	cin >> L;

	while (L--) {
		int X;	// 몇 초후에 방향전환을 할 것인지?
		char C;	// L : 왼쪽, D : 오른쪽
		cin >> X >> C;
		direction.push(make_pair(X, C));
	}

	snake.push(make_pair(1, 1));	//1,1에서 시작;
	move(N);

	cout << sec << endl;
}