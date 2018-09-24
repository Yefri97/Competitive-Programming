#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

ll g(int m, vi &a) {
	int n = a.size();
	vi s(n + 1);
	fori(i, 1, n + 1)
		s[i] = (a[i - 1] < m ? -1 : 1);
	fori(i, 1, n + 1)
		s[i] += s[i - 1];
	vi c(2 * n + 1); c[s[0] + n]++;
	ll ans = 0, cnt = 0;
	fori(i, 1, n + 1) {
		cnt += (a[i - 1] < m ? -c[s[i] + n] : c[s[i - 1] + n]);
		c[s[i] + n]++;
		ans += cnt;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	ll ans = g(m, a) - g(m + 1, a);
	cout << ans << endl;
	return 0;
}
