#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int can(vi &a, vi &b, ll k) {
	int n = a.size();
	ll s = 0;
	priority_queue<int> pq;
	fori(i, 0, k - 1) {
		pq.push(b[i]);
		s += b[i];
	}
	fori(i, k - 1, n) {
		if (k * a[i] >= s + b[i]) return true;
		pq.push(b[i]); s += b[i];
		s -= pq.top(); pq.pop();
	}
	return false;
}

int solve(vi &a, vi &b) {
	int n = a.size();
	if (!can(a, b, 1)) return 0;
	if (can(a, b, n)) return n;
	int lo = 1, hi = n;
	while (hi - lo > 1) {
		int mi = (hi + lo) / 2;
		if (can(a, b, mi))
			lo = mi;
		else
			hi = mi;
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ii> v(n);
		fori(i, 0, n)
			cin >> v[i].first >> v[i].second;
		sort(v.rbegin(), v.rend());
		vi a(n), b(n);
		fori(i, 0, n) {
			a[i] = v[i].first;
			b[i] = v[i].second;
		}
		int ans = solve(a, b);
		cout << ans << endl;
	}
	return 0;
}
