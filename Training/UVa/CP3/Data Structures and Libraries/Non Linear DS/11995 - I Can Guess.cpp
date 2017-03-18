// C++ STL priority_queue
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int a = 1, b = 1, c = 1;
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		while (n--) {
			int qr, x; cin >> qr >> x;
			if (qr == 1) {
				s.push(x);
				q.push(x);
				pq.push(x);
			} else {
				if (s.empty() || q.empty() || pq.empty()) { 
					a = b = c = 0;
				} else {
					if (s.top() != x) a = 0;
					if (q.front() != x) b = 0;
					if (pq.top() != x) c = 0;
					s.pop();
					q.pop();
					pq.pop();
				}
			}
		}
		int ans = a + b + c;
		if (ans == 0) {
			cout << "impossible" << endl;
		} else if (ans == 1) {
			if (a) cout << "stack" << endl;
			if (b) cout << "queue" << endl;
			if (c) cout << "priority queue" << endl;
		} else {
			cout << "not sure" << endl;
		}
	}
	return 0;
}