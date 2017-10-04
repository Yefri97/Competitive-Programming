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

const int oo = 1e9, mxn = 110;

int A[mxn], B[mxn];
vi visited, matched, g[2 * mxn];

int dfs(int u) {
	if (visited[u]) return 0;
	visited[u] = 1;
	fori(i, 0, g[u].size()) {
		int v = g[u][i];
		if (matched[v] == -1 || dfs(matched[v])) {
			matched[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n) g[i].clear();
		fori(i, 0, n)
			cin >> A[i];
		int m; cin >> m;
		fori(i, 0, m)
			cin >> B[i];
		fori(i, 0, n) {
			fori(j, 0, m) {
				if ((A[i] == 0 && B[j] == 0) || (A[i] != 0 && (B[j] % A[i]) == 0)) {
					g[i].push_back(j);
				}
			}
		}
		int mcbm = 0;
		matched.assign(m, -1);
		fori(i, 0, n) {
			visited.assign(n, 0);
			mcbm += dfs(i);
		}
		cout << "Case " << ++cs << ": " << mcbm << endl;
	}
	return 0;
}