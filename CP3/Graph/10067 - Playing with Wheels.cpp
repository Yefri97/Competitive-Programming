#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c, d;
	node(int _a, int _b, int _c, int _d) { a = _a; b = _b; c = _c; d = _d; }
	
	bool operator < (node x) const {
		return ((a < x.a) ||
				(a == x.a && b < x.b) ||
				(a == x.a && b == x.b && c < x.c) ||
				(a == x.a && b == x.b && c == x.c && d < x.d));
	}

	bool operator == (node x) const {
		return (a == x.a && b == x.b && c == x.c && d == x.d);
	}
};

typedef pair<int, node> in;

int mov[10][5] =  {{0, 0, 0,  1}, 
					{0, 0, 0, -1},
					{0, 0,  1, 0},
					{0, 0, -1, 0},
					{0,  1, 0, 0},
					{0, -1, 0, 0},
					{ 1, 0, 0, 0},
					{-1, 0, 0, 0}};

int mod(int n, int m) {
	return (n % m + m) % m;
}

set<node> sn;

int bfs(node initial, node target) {
	sn.insert(initial);
	queue<in> q; q.push(in(0, initial));
	while (!q.empty()) {
		in front = q.front(); q.pop();
		node u = front.second;
		if (u == target) return front.first;
		for (int i = 0; i < 8; i++) {
			node v = node(mod(u.a + mov[i][0], 10), mod(u.b + mov[i][1], 10), mod(u.c + mov[i][2], 10), mod(u.d + mov[i][3], 10));
			if (!sn.count(v)) {
				sn.insert(v);
				q.push(in(front.first + 1, v));
			}
		}
	}
	return -1;
}

int main() {
	int t; cin >> t;
	while (t--) {
		sn.clear();
		int a, b, c, d; 
		cin >> a >> b >> c >> d;
		node no = node(a, b, c, d);
		cin >> a >> b >> c >> d;
		node nf = node(a, b, c, d);
		int n; cin >> n;
		while (n--) {
			cin >> a >> b >> c >> d;
			sn.insert(node(a, b, c, d));
		}
		int ans = bfs(no, nf);
		cout << ans << endl;
	}
	return 0;
}