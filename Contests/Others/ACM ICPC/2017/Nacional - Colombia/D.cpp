#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 100010;

int pt, n, k;
int used[MX][30];
stack<int> s;

void dfs(int u) {
	fori(i, 0, k) {
		if (used[u][i]) continue;
		used[u][i] = 1;
		int v = (u % pt) * k + i;
		dfs(v);
	}
	s.push(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> k >> n) {
		if (k == 1) { cout << string(n, 'A') << endl; continue; }
		if (n == 1) { fori(i, 0, k) cout << (char)('A' + i); cout << endl; continue; }
		memset(used, 0, sizeof used);
		pt = 1;
		fori(i, 0, n - 2)
			pt *= k;
		dfs(0);
		string ans;
		while (true) {
			int u = s.top(); s.pop();
			if (s.empty()) break;
			ans.push_back('A' + u % k);
		}
		int m = ans.size();
		ans += ans;
		int it = m - 1;
		while (ans[it] == 'A') it--;
		ans = ans.substr(it + 1, m);
		cout << ans << endl;
	}
	return 0;
}
