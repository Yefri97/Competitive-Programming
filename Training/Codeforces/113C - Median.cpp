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

const int oo = 1e9, mxn = 510;
int A[mxn];

int go(int i, int n) { return min(abs(2 * i - n - 1), abs(2 * i - n)); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, x; cin >> n >> x;
	fori(i, 0, n)
		cin >> A[i];
	sort(A, A + n);
	int l = (lower_bound(A, A + n, x) - A) + 1;
	int r = (upper_bound(A, A + n, x) - A) + 1;
	int ans = oo;
	if (l == r) {
		ans = go(l, n + 1) + 1;
	} else {
		fori(i, l, r)
			ans = min(ans, go(i, n));
	}
	cout << ans << endl;
	return 0;
}