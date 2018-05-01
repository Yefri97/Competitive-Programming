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
	int t; cin >> t;
	while (t--) {
		int n, b, r; cin >> n >> b >> r;
		vi from(101, -1);
		fori(i, 0, b) {
			int u, v; cin >> u >> v;
			from[u] = v;
		}
		int win = 0;
		vi curr(n, 1);
		fori(i, 0, r) {
			int o; cin >> o;
			if (win) continue;
			int p = i % n;
			curr[p] = min(100, curr[p] + o);
			if (from[curr[p]] != -1) curr[p] = from[curr[p]];
			if (curr[p] == 100) win = 1;
		}
		fori(i, 0, n)
			cout << "Position of player " << i + 1 << " is " << curr[i] << "." << endl;
	}
	return 0;
}