#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 100010;
ll A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n) {
		ll x; cin >> x;
		A[i] = B[i] = x;
	}
	sort(B, B + n);
	fori(i, 1, n) A[i] += A[i - 1];
	fori(i, 1, n) B[i] += B[i - 1];
	int m; cin >> m;
	fori(i, 0, m) {
		int t, l, r; cin >> t >> l >> r; l--; r--;
		if (t == 1) {
			cout << A[r] - (l ? A[l - 1] : 0) << endl;
		} else {
			cout << B[r] - (l ? B[l - 1] : 0) << endl;
		}
	}
	return 0;
}