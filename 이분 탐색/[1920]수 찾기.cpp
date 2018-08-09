// insert : O(n), search : O(nlogn)
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> v;
//
//bool search(int num, int start, int end) {
//	if (start > end)
//		return 0;
//
//	int mid = (start + end) / 2;
//
//	if (v[mid] == num)
//		return 1;
//	else if (num < v[mid])
//		return search(num, start, mid - 1);
//	else if (v[mid] < num)
//		return search(num, mid + 1, end);
//
//}
//
//int main() {
//	int N, M;
//	scanf("%d", &N);
//
//	v.resize(N);
//	for (int i = 0; i < N; i++) {
//		int input;
//		scanf("%d", &input);
//		v[i] = input;
//	}
//
//	sort(v.begin(), v.end());
//
//	scanf("%d", &M);
//	for (int i = 0; i < M; i++) {
//		int input;
//		scanf("%d", &input);
//		printf("%d\n", search(input, 0, N - 1));
//	}
//}

// MapÀ» ÀÌ¿ë insert : O(nlogn) search(nlogn)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, bool> m;

int main() {
	int N, M;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		m[input] = true;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int input;
		scanf("%d", &input);
		printf("%d\n", m[input]);
	}
}