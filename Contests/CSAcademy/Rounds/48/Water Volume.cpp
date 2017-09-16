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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, acc = 0, mmin = 0, mmax = 0; cin >> n;
	while (n--) {
		int t, x; cin >> t >> x;
		acc += (t == 0 ? x : -x);
		mmin = min(mmin, acc);
		mmax = max(mmax, acc);
	}
	if (mmin < 0) mmax -= mmin;
	cout << mmax << endl;
	return 0;
}