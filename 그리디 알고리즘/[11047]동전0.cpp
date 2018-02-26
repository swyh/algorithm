#include <iostream>
using namespace std;

int result = 1000, cnt = 0;

void func(int m) {
	while (result >= m) {
		result -= m;
		cnt++;
	}

}

int main() {
	int N;
	cin >> N;
	
	result -= N;
	
		func(500);
		func(100);
		func(50);
		func(10);
		func(5);
		func(1);
		cout << cnt << endl;
}