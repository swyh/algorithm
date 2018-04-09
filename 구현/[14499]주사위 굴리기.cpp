#include <iostream>
#include <vector>
using namespace std;

#define FRONT 0
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
#define BACK 5

//  동 서 북 남
int di[5] = { 0,0,0,-1,1 };
int dj[5] = { 0,1,-1,0,0 };

vector<vector<int>> v;	// 지도를 담음
int N, M, x, y, K; // 가로, 세로, 좌표(x,y), 명령어 개수


class Dice {
private:

	// 주사위를 구현한다.
	int dice[6] = { 0,0,0,0,0,0 };

	int front = FRONT;

	int east = EAST;//동쪽
	int west = WEST;//서쪽
	int north = NORTH;// 북쪽
	int south = SOUTH;// 남쪽

	int back = BACK;


public:
	void change(int direction) {	// 이동함에 따라 index를 바꿈
		int t_front = front;	// 원래 있던 값 저장
		int t_back = back;
		if (direction == EAST) {
			front = east;	// 앞면은 원래의 동쪽으로
			back = west;		// 뒷쪽은 원래의 서쪽으로

			east = t_back;	// 동쪽은 원래의 뒷면으로
			west = t_front;	// 서쪽은 원래의 앞면으로
		}
		else if (direction == WEST) {
			front = west;
			back = east;

			west = t_back;
			east = t_front;
		}
		else if (direction == NORTH) {
			front = north;
			back = south;

			north = t_back;
			south = t_front;
		}
		else if (direction == SOUTH) {
			front = south;
			back = north;

			south = t_back;
			north = t_front;
		}
	}

	int getFront() {	// 앞면을 리턴
		return dice[front];
	}

	int getBack() {
		return dice[back];
	}

	void setBack(int num) {
		dice[back] = num;
	}

	int copy(int copyNum) {
		if (copyNum == 0) {
			return getBack();
		}
		else {
			setBack(copyNum);
			return 0;
		}
	}
};

bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return 0;
	else
		return 1;
}

void move(int direction, Dice& dice) {
	//cout << x << ", " << y << endl;
	int move_i = x + di[direction];
	int move_j = y + dj[direction];

	if (!check(move_i, move_j))
		return;

	x = move_i;
	y = move_j;

	dice.change(direction);
	v[x][y] = dice.copy(v[x][y]);
	cout << dice.getFront() << endl;
}

int main() {
	cin >> N >> M >> x >> y >> K;

	v.resize(N);
	Dice dice;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			v[i].push_back(input);
		}
	}

	while (K--) {
		int direction;
		cin >> direction;
		move(direction, dice);
	}
}