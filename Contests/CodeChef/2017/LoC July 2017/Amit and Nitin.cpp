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

const int oo = 1e9, mxn = 32;

ll A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	A[1] = 2;
	A[2] = 7;
	fori (i, 3, mxn)
		A[i] = (i % 2 ? 3 * A[i - 2] + A[i - 1] : A[i - 1] + 7);
	set<ll> st;
	fori(i, 1, mxn) {
		vi v;
		for (ll x : st)
			v.push_back(x);
		st.insert(A[i]);
		for (ll x : v)
			st.insert(x + A[i]);
	}
	set<ll>::iterator it = st.end(); it--;
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		cout << (st.find(x) == st.end() ? "NO" : "YES") << endl;
	}
	return 0;
}