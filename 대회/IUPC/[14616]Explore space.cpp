#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {	
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int temp = N;
	list<pair<double,double>> v;
	while (N--) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		double a1, a2;
		a1 = (double)(y1 / x1);
		a2 = (double)(y2 / x2);
		if(a1 > a2)
			v.push_back(make_pair(a1, a2));
		else
			v.push_back(make_pair(a2, a1));
	}

	int M;
	cin >> M;
	int cnt = 0;
	while (M--) {
		double x3, y3;
		cin >> x3 >> y3;

		double a3;
		a3 = (double)(y3 / x3);

		list<pair<double, double>>::iterator iter = v.begin();

		while(iter != v.end()){
			if (iter->first >= a3 &&iter->second <= a3){
					list<pair<double, double>>::iterator temp = iter;
					iter = v.erase(temp);
					cnt++;
			}
			else iter++;
		}
	}
	cout << v.size() << '\n';

	return 0;
}