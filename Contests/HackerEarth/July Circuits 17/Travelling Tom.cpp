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

int from[mxn], to[mxn], removed[mxn];
int q[mxn], taken[mxn];
ll need[mxn], tokens[70];
vi g[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	fori(i, 0, k)
		cin >> tokens[i];
	fori(i, 0, m) {
		int u, v, l; cin >> u >> v >> l; u--; v--;
		from[i] = u;
		to[i] = v;
		g[u].push_back(i);
		g[v].push_back(i);
		while (l--) {
			int x; cin >> x; x--;
			need[i] |= (1LL << x);
		}
	}
	ll ans = 0;
	for (int i = k; i >= 0; i--) {
		int h = 0, t = 0, cnt = 0;
		q[t++] = 0;
		memset(taken, 0, sizeof taken);
		while (t > h) {
			int u = q[h++];
			fori(j, 0, g[u].size()) {
				int e = g[u][j];
				if (removed[e] || need[e] & (1LL << i)) continue;
				int v = (from[e] + to[e]) - u;
				if (!taken[v]) {
					q[t++] = v;
					taken[v] = 1;
					cnt++;
				}
			}
		}
		if (i == k && cnt != n) { ans = -1; break; }
		if (cnt == n) {
			fori(j, 0, m) if (need[j] & (1LL << i))
				removed[j] = 1;
		} else {
			ans += tokens[i];
		}
	}
	cout << ans << endl;
	return 0;
}