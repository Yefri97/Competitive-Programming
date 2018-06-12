#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 100010;
ll snakes[MAXN], d[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n, l, a, b; cin >> n >> l >> a >> b;
		fori(i, 0, n)
			cin >> snakes[i];
		sort(snakes, snakes + n);
		for (ll i = 0; i < n; i++)
			d[i] = (snakes[0] + i * l) - snakes[i];
		sort(d, d + n);
		ll c = b - n * l;
		ll low = a - snakes[0], high = c - snakes[0], median = -d[n / 2];
		median = max(median, low);
		median = min(median, high);
		ll ans = 0;
		fori(i, 0, n)
			ans += abs(d[i] + median);
		cout << ans << endl;
	}
	return 0;
}