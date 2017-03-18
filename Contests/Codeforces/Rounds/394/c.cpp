#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

struct st {
	int a, b, c;
	st(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

bool issimbol(char c) { return (c == '#' || c == '*' || c == '&'); }

int main() {
	int n, m; cin >> n >> m;
	vector<st> v;
	for (int i = 0; i < n; i++) {
		st x = st(INF, INF, INF);
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (isdigit(c)) x.a = min(x.a, min(j, m - j));
			if (islower(c)) x.b = min(x.b, min(j, m - j));
			if (issimbol(c)) x.c = min(x.c, min(j, m - j));
		}
		v.push_back(x);
	}
	int ans = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				if (i == j || i == k || j == k) continue;
				ans = min(ans, v[i].a + v[j].b + v[k].c);
			}
	cout << ans << endl;
	return 0;
}