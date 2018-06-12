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
	int n; cin >> n;
	set<ll> s;
	fori(i, 0, n) {
		ll x; cin >> x;
		s.insert(x);
	}
	ll ans;
	for (ll c : s) {
		ll t = c;
		int cnt = 0;
		while (true) {
			if (s.count(2 * t)) t = 2 * t;
			else if (t % 3 == 0 && s.count(t / 3)) t = t / 3;
			else break;
			cnt++;
		}
		if (cnt == n - 1) ans = c;
	}
	ll t = ans;
	cout << t;
	fori(i, 0, n - 1) {
		if (s.count(2 * t)) t = 2 * t;
		else if (t % 3 == 0 && s.count(t / 3)) t = t / 3;
		cout << " " << t;
	}
	cout << endl;
	return 0;
}
