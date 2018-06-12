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

const int mxn = 100010;
const ll oo = 1e11;

int n;
int A[mxn];

int calc(ll x) {
	int l = 0, r = 0, ans = 0;
	ll acc = 0;
	while (l < n) {
		while (r < n && acc + A[r] <= x) acc += A[r], r++;
		ans++;
		acc = 0;
		l = r;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k;
	while (cin >> n >> k) {
		fori(i, 0, n)
			cin >> A[i];
		int max_val = *max_element(A, A + n);
		ll low = 0, high = oo;
		while (high - low > 1) {
			ll mid = (high + low) / 2;
			if (mid >= max_val && calc(mid) <= k)
				high = mid;
			else
				low = mid;
		}
		cout << high << endl;
	}
	return 0;
}