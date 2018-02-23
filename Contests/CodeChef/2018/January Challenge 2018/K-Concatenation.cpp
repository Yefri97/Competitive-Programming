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

const int oo = 1e9, MX = 2e5 + 10;

ll A[MX];

ll solver(ll n) {
	ll sum = 0, ans = -oo;
	fori(i, 0, n) {
		sum += A[i];
		ans = max(ans, sum);
		if (sum < 0)
			sum = 0;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		fori(i, 0, n) {
			ll x; cin >> x;
			A[i] = A[n + i] = x;
		}
		ll ans = 0;
		if (k == 1) {
			ans += solver(n);
		} else {
			ll acc = accumulate(A, A + n, 0LL);
			if (acc > 0) {
				ans += (k - 2) * acc;
				ll a = 0, b = 0, sum1 = 0, sum2 = 0;
				fori(i, 0, n) {
					sum1 += A[i];
					sum2 += A[n - i - 1];
					a = max(a, sum1);
					b = max(b, sum2);
				}
				ans += a + b;
				ans = max(ans, solver(2 * n));
			} else {
				ans += solver(2 * n);
			}
		}
		cout << ans << endl;
	}
	return 0;
}