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

const int oo = 1e9, mxn = 100000;

ll freq[mxn + 10], best[mxn + 10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x;
		freq[x]++;
	}
	best[mxn] = freq[mxn] * mxn;
	best[mxn - 1] = max(best[mxn], freq[mxn - 1] * (mxn - 1));
	for (ll i = mxn - 2; i >= 1; i--)
		best[i] = max(best[i + 1], best[i + 2] + freq[i] * i);
	cout << best[1] << endl;
	return 0;
}