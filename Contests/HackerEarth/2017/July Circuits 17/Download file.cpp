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

const int oo = 1e9, mxn = 2000010;

int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, s; cin >> n >> s;
	fori(i, 0, n) {
		int t, d; cin >> t >> d;
		A[t] = d;
	}
	int curr = 0;
	fori(i, 0, mxn) {
		curr = (A[i] ? A[i] : curr);
		A[i] = curr;
	}
	ll l = 0, r = 0, p = s, q = 1, acc = 0;
	while (l < mxn) {
		while (r < mxn && acc < s) acc += A[r++];
		if (acc < s) break;
		ll curr = A[r-1], a = curr * (r - l) - (acc - s), b = curr;
		if (a * q < b * p) {
			p = a;
			q = b;
		}
		acc -= A[l];
		l++;
	}
	reverse(A, A + mxn);
	l = 0; r = 0; acc = 0;
	while (l < mxn) {
		while (r < mxn && acc < s) acc += A[r++];
		if (acc < s) break;
		ll curr = A[r-1], a = curr * (r - l) - (acc - s), b = curr;
		if (a * q < b * p) {
			p = a;
			q = b;
		}
		acc -= A[l];
		l++;
	}
	cout << p / __gcd(p, q) << "/" << q / __gcd(p, q) << endl;
	return 0;
}