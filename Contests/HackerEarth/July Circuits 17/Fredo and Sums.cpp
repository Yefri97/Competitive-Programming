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

ll A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n)
			cin >> A[i];
		sort(A, A + n);
		ll min_val = 0, max_val = 0;
		fori(i, 0, n) min_val += (i % 2 ? A[i] : -A[i]);
		fori(i, 0, n) max_val += (2 * i < n ? -A[i] : A[i]);
		cout << min_val << " " << max_val << endl;
	}
	return 0;
}