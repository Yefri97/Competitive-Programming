#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int n, k;
ii ans;

void gen(int pl, int ql, int ph, int qh) {
	int pm = pl + ph, qm = ql + qh, gcd = __gcd(pm, qm);
	pm /= gcd; qm /= gcd;
	if (qm > n) return;
	gen(pl, ql, pm, qm);
	if (k == 1) ans = ii(pm, qm);
	k--;
	gen(pm, qm, ph, qh);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> k) {
		gen(0, 1, 1, 1);
		if (k == 1) ans = ii(1, 1);
		cout << ans.first << "/" << ans.second << endl;
	}
	return 0;
}