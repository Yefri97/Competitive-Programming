#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 2e6;
ll S[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (ll i = 1; i < mxn; i++)
		S[i] = i * i;
	ll a, b; cin >> a >> b;
	ll ans = 0;
	for (ll i = 1; i <= a; i++) {
		int l = upper_bound(S, S + mxn, i * i + 1) - S;
		int r = upper_bound(S, S + mxn, i * i + b) - S;
		ans += (r - l);
	}
	cout << ans << endl;
	return 0;
}