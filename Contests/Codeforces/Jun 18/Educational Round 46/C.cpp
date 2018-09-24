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
	map<ll, int> a;
	fori(i, 0, n) {
		ll l, r; cin >> l >> r;
		a[l]++;
		a[r + 1]--;
	}
	vector<ll> ans(n + 1);
	ll c = 0, prev = 0;
	for (auto x : a) {
		ll curr = x.first, acc = x.second;
		ans[c] += curr - prev;
		c += acc;
		prev = curr;
	}
	fori(i, 1, n + 1)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
