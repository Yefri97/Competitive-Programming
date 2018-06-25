#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll oo = 1e14;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vi prev(n), s(m), a(k);
	fori(i, 0, n) prev[i] = i;
	fori(i, 0, m) {
		int x; cin >> x;
		prev[x] = -1;
	}
	fori(i, 0, k)
		cin >> a[i];
	if (prev[0] == -1) { cout << -1 << endl; return 0; }
	fori(i, 1, n) if (prev[i] == -1)
		prev[i] = prev[i - 1];
	ll ans = oo;
	fori(i, 1, k + 1) {
		int j = 0, cnt = 0;
		while (j + i < n) {
			if (prev[j + i] == j) { cnt = -1; break; }
			j = prev[j + i];
			cnt++;
		}
		if (cnt != -1)
			ans = min(ans, 1LL * (cnt + 1) * a[i - 1]);
	}
	cout << (ans < oo ? ans : -1) << endl;
	return 0;
}
