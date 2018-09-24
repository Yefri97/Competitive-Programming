#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

int a[MN], s[MN];

int on(int r, int l) { return s[r] - s[l]; }
int off(int r, int l) { return a[r] - a[l] - on(r, l); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 1, n + 1)
		cin >> a[i];
	a[n + 1] = m;
	for (int i = 1; i < n + 2; i += 2)
		s[i] = s[i + 1] = a[i] - a[i - 1] + s[i - 1];
	int ans = on(n + 1, 0);
	fori(i, 0, n + 1) {
		if (a[i + 1] - a[i] == 1) continue;
		if (i % 2)
			ans = max(ans, on(i, 0) + off(n + 1, i) - 1);
		else
			ans = max(ans, on(i + 1, 0) + off(n + 1, i + 1) - 1);
	}
	cout << ans << endl;
	return 0;
}
