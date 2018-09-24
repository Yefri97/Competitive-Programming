#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 26;

vi a[MN];

int check(int i, int j, int k) {
	if (SZ(a[i]) == 0) return 0;
	int p = a[i][0], it = 0;
	it = upper_bound(a[j].begin(), a[j].end(), p) - a[j].begin();
	if (it == SZ(a[j])) return 0;
	p = a[j][it];
	it = upper_bound(a[k].begin(), a[k].end(), p) - a[k].begin();
	if (it == SZ(a[k])) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		fori(i, 0, 26)
			a[i].clear();
		string s; cin >> s;
		int n = SZ(s);
		fori(i, 0, n)
			a[s[i] - 'A'].push_back(i);
		int ans = 0;
		fori(i, 0, 26)
			fori(j, 0, 26)
				fori(k, 0, 26)
					ans += check(i, j, k);
		cout << ans << endl;
	}
	return 0;
}
