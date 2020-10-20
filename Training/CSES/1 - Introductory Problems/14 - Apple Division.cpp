#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int bit(int b, int mask) { return (mask >> b) & 1; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	ll ans = oo;
	fori(mask, 0, (1 << n)) {
		vector<ll> sum(2);
		fori(b, 0, n)
			sum[bit(b, mask)] += a[b];
		ans = min(ans, abs(sum[0] - sum[1]));
	}
	cout << ans << endl;
	return 0;
}
