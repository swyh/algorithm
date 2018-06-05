//Matrix Chain Multiplication Problem
#include <iostream>
#include <vector>
using namespace std;

unsigned int matix_chain_order(vector<int>& p) {
	int n = p.size() - 1;
	vector<vector<unsigned int>> m(n + 1);

	for (int i = 1; i <= n; i++)
		m[i].resize(n + 1);

	for (int l = 2; l <= n; l++) {	// l : 매트릭스 체인의 개수
		for (int i = 1; i <= n - l + 1; i++) {	// 시작점
			int j = i + l - 1;		// 끝점(i부터의 l개)
			m[i][j] = 0xffffffff;
			for (int k = i; k <= j - 1; k++) {	// 가운데
				unsigned int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])	// 더 작은 값으로 갱신
					m[i][j] = q;
			}
		}
	}
	return m[1][n];
}

int main() {
	int N;
	cin >> N;
	vector<int> p;

	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;

		if (i == 0)
			p.push_back(r);
		p.push_back(c);
	}

	cout << matix_chain_order(p) << endl;

	return 0;
}