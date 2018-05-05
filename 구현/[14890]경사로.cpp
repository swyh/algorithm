#include <iostream>
#include <vector>
using namespace std;

int N, L;	// map의 크기, 경사로의 크기

bool check(int i) {
	if (i < 0 || i >= N)
		return 0;
	else
		return 1;
}

bool low(int arr[], int visit[], int i) {	// 앞으로 갈 경로에 경사로를 깔음
	for (int j = i; j < i + L; j++) {
		if (!check(j) || visit[j] == 1)
			return 0;
	}
	for (int j = i; j < i + L; j++)
		visit[j] = 1;
	return 1;
}

bool high(int arr[], int visit[], int i) {	// 뒤에 경사로 놓을 자리가 있는지 확인
	for (int j = i; j > i - L; j--) {
		if (!check(j) || visit[j] == 1)
			return 0;
	}
	for (int j = i; j > i - L; j--)
		visit[j] = 1;
	return 1;
}

bool move(int arr[]) {
	int* visit = new int[N];
	for (int i = 0; i < N; i++)
		visit[i] = 0;

	for (int i = 0; i < N - 1; i++) {
		//가면서 더 높은 것, 낮은 것 만나면
		//경사로 넣을 수 있는 지 확인 => yes : 넘어감, no : false
		if (arr[i] == arr[i + 1])	// 넘어감
			continue;
		else if (arr[i] == arr[i + 1] - 1) {	// 경사가 1칸 높음
			if (high(arr, visit, i) == false)
				return 0;
		}
		else if (arr[i] == arr[i + 1] + 1) { // 경사가 한칸 낮음
			if (low(arr, visit, i + 1) == false)
				return 0;
		}
		else
			return 0;
	}
	return 1;
}

int main() {

	cin >> N >> L;

	vector<vector<int>> v;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		v[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	int cnt = 0;

	//가로줄
	for (int i = 0; i < N; i++) {
		int* arr = new int[N];
		for (int j = 0; j < N; j++) {
			arr[j] = v[i][j];
		}
		cnt += move(arr);
	}

	//세로줄
	for (int i = 0; i < N; i++) {
		int* arr = new int[N];
		for (int j = 0; j < N; j++) {
			arr[j] = v[j][i];
		}
		cnt += move(arr);
	}
	cout << cnt << endl;
}

//틀렸던 이유 : 경사로 하나에 한칸만 올릴 수 있다는 점 간과
// 참고 : 매개변수에서 int arr[]은 포인터로 지정하여 원본값에 영향이 감