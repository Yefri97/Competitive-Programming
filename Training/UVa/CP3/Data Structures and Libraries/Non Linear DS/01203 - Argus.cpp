// C++ STL priority_queue
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair< int, ii > iii;

int main() {
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	string rg;
	while (cin >> rg && rg != "#") {
		int id, x; cin >> id >> x;
		pq.push(iii(x, ii(id, x)));
	}
	int k; cin >> k;
	while (k--) {
		iii tp = pq.top();
		pq.pop();
		cout << tp.second.first << endl;
		pq.push(iii(tp.first + tp.second.second, tp.second));
	}
	return 0;
}