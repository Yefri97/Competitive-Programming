// C++ STL priority_queue
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		priority_queue< int, vector<int>, greater<int> > pq;
		while (n--) {
			int x; cin >> x;
			pq.push(x);
		}
		int cost = 0;
		while (pq.size() > 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			int add = a + b;
			pq.push(add);
			cost += add;
		}
		cout << cost << endl;
	}
	return 0;
}