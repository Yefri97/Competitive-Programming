// C++ STL queue
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
int n;
queue<int> vq[MAX_N + 10];
stack<int> carry;

bool done() {
	for (int i = 0; i < n; i++)
		if (!vq[i].empty()) return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int cc, cp; cin >> n >> cc >> cp;
		for (int i = 0; i < n; i++) {
			int m; cin >> m;
			while (m--) {
				int x; cin >> x; x--;
				vq[i].push(x);
			}
		}
		int curr = 0, ans = 0;
		while (true) {
			while (!carry.empty() && (carry.top() == curr || vq[curr].size() < cp)) {
				if (carry.top() != curr) vq[curr].push(carry.top());
				carry.pop();
				ans++;
			}
			if (done() && carry.empty()) break;
			while (!vq[curr].empty() && carry.size() < cc) {
				carry.push(vq[curr].front());
				vq[curr].pop();
				ans++;
			}
			curr = (curr + 1) % n;
			ans += 2;
		}
		cout << ans << endl;
	}
	return 0;
}