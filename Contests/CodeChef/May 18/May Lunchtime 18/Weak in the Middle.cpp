#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi a(n), l(n), r(n);
		fori(i, 0, n)
			cin >> a[i];
		fori(i, 0, n) {
			l[i] = i - 1;
			r[i] = i + 1;
		}
		vi day(n);
		queue<int> q;
		fori(i, 1, n - 1) if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
			day[i] = 1;
			q.push(i);
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (a[l[u]] == a[r[u]]) continue;
			int v = (a[l[u]] < a[r[u]] ? l[u] : r[u]);
			if (v == 0 || v == n - 1) continue;
			r[l[u]] = r[u];
			l[r[u]] = l[u];
			if (a[l[v]] > a[v] && a[r[v]] > a[v]) {
				day[v] = day[u] + 1;
				q.push(v);
			}
		}
		fori(i, 0, n)
			cout << day[i] << " ";
		cout << endl;
	}
	return 0;
}
