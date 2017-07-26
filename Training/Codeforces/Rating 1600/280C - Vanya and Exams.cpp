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

const int oo = 1e9, mxn = 100010;

pair<ll, ll> A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, r, avg; cin >> n >> r >> avg;
	fori(i, 0, n)
		cin >> A[i].second >> A[i].first;
	sort(A, A + n);
	ll acc = 0;
	fori(i, 0, n)
		acc += A[i].second;
	ll curr = n * avg - acc, ans = 0;
	for (int i = 0; curr > 0; i++) {
		ll x = min(curr, r - A[i].second);
		curr -= x;
		ans += x * A[i].first;
	}
	cout << ans << endl;
	return 0;
}