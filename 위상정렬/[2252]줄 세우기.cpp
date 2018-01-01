//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//
//vector<vector<int>> v;
//vector<bool> visit;
//stack<int> s;
//
//void DFS(int n) {	// DFS를 이용한 방법 : 끝까지 가본다. 그런뒤 아웃오브엣지?가 없으면 queue에 넣는다.
//	//그럼 순서대로 되겟쥬??~
//	visit[n] = 1;
//
//	for (int i = 0; i < v[n].size(); i++) {
//		int k = v[n][i];
//		if (visit[k] == 0)
//			DFS(k);
//	}
//	s.push(n);
//}
//// 위상정렬에는 2가지 방법이 있다. 1.DFS, 2.topo,,?토 어쩌구
//// 이건 DFS를 이용한 방법!
//int main() {
//	int N, M;	// N : 인원, M :키를 비교 횟수
//	cin >> N >> M;
//
//	v.resize(N + 1);
//	visit.resize(N + 1);
//	for (int i = 0; i < M; i++) {
//		int A, B;
//		cin >> A >> B;
//		v[A].push_back(B);	// A는 B 앞에 있다
//	}
//
//	for (int i = 1; i <= N; i++) {	// 순회한다.
//		if (visit[i] == 0)
//			DFS(i);
//	}
//	while (!s.empty()) {
//		cout << s.top() << " ";
//		s.pop();
//	}
//	cout << endl;
//	return 0;
//}


//2017-12-15 update... queue를 이용하여 명확하게
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<bool> visit;
stack<int> s;

void DFS(int n) {	// DFS를 이용한 방법 : 끝까지 가본다. 그런뒤 아웃오브엣지?가 없으면 queue에 넣는다.
					//그럼 순서대로 되겟쥬??~
	visit[n] = 1;

	for (int i = 0; i < v[n].size(); i++) {
		int k = v[n][i];
		if (visit[k] == 0)
			DFS(k);
	}
	s.push(n);
}
// 위상정렬에는 2가지 방법이 있다. 1.DFS, 2.topo,,?토 어쩌구
// 이건 DFS를 이용한 방법!
int main() {
	int N, M;	// N : 인원, M :키를 비교 횟수
	cin >> N >> M;

	v.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);	// A는 B 앞에 있다
	}

	for (int i = 1; i <= N; i++) {	// 순회한다.
		if (visit[i] == 0)
			DFS(i);
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
}