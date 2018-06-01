#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 10010;
const ll MD = 212345678987654369LL;

int n;
ll cnt[MN];

ll sum(ll a, ll b) {
	ll res = a + b;
	if (res >= MD) res -= MD;
	return res;
}

void add(int x) {
	for (int i = n; i - x >= 0; i--)
		cnt[i] = sum(cnt[i], cnt[i - x]);
}

void remove(int x) {
	for (int i = x; i <= n; i++)
		cnt[i] = sum(cnt[i], MD - cnt[i - x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> n >> q;
	vector<vi> in(n + 1), out(n + 1);
	fori(i, 0, q) {
		int l, r, x; cin >> l >> r >> x; l--; r--;
		in[l].push_back(x);
		out[r + 1].push_back(x);
	}
	cnt[0] = 1;
	bitset<MN> bs;
	fori(i, 0, n + 1) {
		for (int x : in[i])
			add(x);
		for (int x : out[i])
			remove(x);
		fori(j, 0, n + 1)
			bs[j] = (bs[j] | cnt[j] > 0);
	}
	vi ans;
	fori(i, 1, n + 1)
		if (bs[i])
			ans.push_back(i);
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}
