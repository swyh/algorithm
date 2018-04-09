#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	//input
	int N; // 시험장의 개수
	cin >> N;

	vector<int> v; // 각 방의 응시자의 수를 저장
	int A; // 각 방의 응시자의 수
	for (int i = 0; i < N; i++) {
		cin >> A;
		v.push_back(A);
	}

	int B, C;	// 총감독관, 부감독관이 감독할 수 있는 응시자 수
	cin >> B >> C;


	//request output : 필요한 감독관 수의 최소값
	long long cnt = N;	// N개의 방만큼 총감독관의 수가 필요
	for (int i = 0; i < N; i++) {
		v[i] -= B;	// 총감독관이 감독하는 응시자를 빼고,
		if (v[i] <= 0)	// 0보다 작거나 같다면 다음 방 검색으로 넘어감
			continue;
		cnt += ceil(((double)v[i] / (double)C)); // 필요한 부감독관 구하고 더함
	}

	cout << cnt << endl;	//결과 출력
}