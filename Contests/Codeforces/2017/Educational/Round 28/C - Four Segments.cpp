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
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;

const ll oo = 1e16, mxn = 5010;

int n;
ll A[mxn], sum[mxn];

iii solver(int k) {
	ll acc = 0, ans = 0, l = k, r = k + 1;
	ii pos;
	fori(i, k, n) {
		acc += A[i];
		if (acc > ans) {
			pos.first = l;
			pos.second = r;
			ans = acc;
		}
		if (acc < 0) {
			l = i + 1;
			r = i + 1;
			acc = 0;
		}
		r++;
	}
	return iii(ans, pos);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n) {
		fori(i, 0, n)
			cin >> A[i];
		sum[n] = 0;
		fori(i, 0, n)
			sum[n - i - 1] = A[n - i - 1] + sum[n - i];
		ll ans = -oo, acc = 0, a = 0, b = 0, c = 0;
		fori(i, 0, n + 1) {
			iii x = solver(i);
			ll val = acc - sum[i] + 2 * x.first;
			if (val > ans) {
				a = i;
				b = x.second.first;
				c = x.second.second;
				ans = val;
			}
			acc += A[i];
		}
		cout << a << " " << b << " " << c << endl;
	}
	return 0;
}