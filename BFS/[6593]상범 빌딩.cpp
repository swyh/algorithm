#include <iostream>
#include <queue>
using namespace std;

int dl[6] = { 1,-1,0,0,0,0 };
int di[6] = { 0,0,1,-1,0,0 };
int dj[6] = { 0,0,0,0,-1,1 };
int L, R, C; // ºôµù Ãþ¼ö, Çà, ¿­

bool check(int l, int i, int j) {
	if (l < 0 || i < 0 || j < 0 || l >= L || i >= R || j >= C)
		return 0;
	else
		return 1;
}

class info {
public:
	int l;
	int i;
	int j;

	info(int l, int i, int j) {
		this->l = l;
		this->i = i;
		this->j = j;
	}

	info() {
		l = 0;
		i = 0;
		j = 0;
	}
};

bool equals(info& a, info& b) {
	if (a.l == b.l && a.i == b.i && a.j == b.j)
		return 1;
	else
		return 0;
}

int main() {
	while (1) {
		bool secc = 0;
		cin >> L >> R >> C;

		if (!L && !R && !C)
			break;

		char v[31][31][31] = { 0 };
		bool visit[31][31][31] = { 0 };
		queue<info> q[2];
		info end;
		bool flag = 0;

		for (int l = 0; l < L; l++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cin >> v[l][i][j];

					if (v[l][i][j] == 'S') {
						q[flag].push(info(l, i, j));
						visit[l][i][j] = 1;
					}
					else if (v[l][i][j] == 'E')
						end = info(l, i, j);
				}
			}
		}

		int time = 0;
		while (!q[flag].empty()) {
			while (!q[flag].empty()) {
				info fi = q[flag].front();
				q[flag].pop();

				if (equals(end, fi)) {
					secc = 1;
					break;
				}

				for (int k = 0; k < 6; k++) {
					int kl = fi.l + dl[k];
					int ki = fi.i + di[k];
					int kj = fi.j + dj[k];

					if (check(kl, ki, kj) && !visit[kl][ki][kj] && v[kl][ki][kj] != '#') {
						visit[kl][ki][kj] = 1;
						q[!flag].push(info(kl, ki, kj));
					}
				}
			}

			if (secc)
				break;

			flag = !flag;
			time++;

		}

		if (secc)
			cout << "Escaped in " << time << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}
}