#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int solve(vi &d) {
	int n = d.size();
	int a = 0;
	fori(i, 0, n) if (d[i] > d[a])
		a = i;
	int b = (a == 0);
	fori(i, 0, n) if (i != a && d[i] > d[b])
		b = i;
	if (d[b] > 2) return -1;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi d(n);
	fori(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		d[u]++;
		d[v]++;
	}
	int id = solve(d);
	if (id == -1) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		if (n == 2) { cout << 1 << endl << 1 << " " << 2 << endl; return 0; }
		vi ans;
		fori(i, 0, n)
			if (d[i] == 1)
				ans.push_back(i);
		cout << ans.size() << endl;
		for (int x : ans)
			cout << id + 1 << " " << x + 1 << endl;
	}
	return 0;
}