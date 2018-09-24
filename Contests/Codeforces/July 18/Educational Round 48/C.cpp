#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi up(n), dw(n);
	fori(i, 0, n)
		cin >> up[i];
	fori(i, 0, n)
		cin >> dw[i];
	vi sum(n);
	fori(i, 0, n)
		sum[i] = up[i] + dw[i];
	fori(i, 1, n)
		sum[n - i - 1] += sum[n - i];
	vi a(n), b(n);
	fori(i, 0, n) {
		a[0] += (i * up[i] + (2 * n - i - 1) * dw[i]);
		b[0] += (i * dw[i] + (2 * n - i - 1) * up[i]);
	}
	fori(i, 1, n) {
		a[i] = a[i - 1] - (2 * (n - i) + 1) * dw[i - 1] - sum[i];
		b[i] = b[i - 1] - (2 * (n - i) + 1) * up[i - 1] - sum[i];
	}
	ll ans = 0, curr = 0;
	fori(i, 0, n) {
		ans = max(ans, curr + (i % 2 ? b[i] : a[i]) + 2 * i * sum[i]);
		if (i % 2)
			curr += (2 * i) * dw[i] + (2 * i + 1) * up[i];
		else
			curr += (2 * i) * up[i] + (2 * i + 1) * dw[i];
	}
	ans = max(ans, curr);
	cout << ans << endl;
	return 0;
}
