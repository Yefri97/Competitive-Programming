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
int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		cin >> A[i];
	ll acc = 0;
	while (m--) {
		int q; cin >> q;
		if (q == 1) {
			int v, x; cin >> v >> x; v--;
			A[v] = x - acc;
		} else if (q == 2) {
			int x; cin >> x;
			acc += x;
		} else {
			int x; cin >> x; x--;
			cout << A[x] + acc << endl;
		}
	}
	return 0;
}