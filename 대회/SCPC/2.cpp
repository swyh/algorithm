#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	int T, test_case;
	FILE* fs = fopen("input.txt", "r");
	//cin >> T;
	fscanf(fs, "%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		//cin >> N;
		fscanf(fs, "%d", &N);

		//vector<long long> v;
		long long min_val = 1000000000;
		long long up = 1000000000;
		long long cnt = 0;
		for (int i = 0; i < N; i++) {
			long long input;
			cin >> input;
			min_val = min(min_val, input);
			if (up > min_val && input > min_val) {
				cnt += 2;
				min_val = 1000000000;
				up = input;
			}
			//cin >> v[i];
		}

		min_val = 0;

		cout << "Case #" << test_case + 1 << "\n";
		cout << cnt << "\n";
	}

	return 0;
}