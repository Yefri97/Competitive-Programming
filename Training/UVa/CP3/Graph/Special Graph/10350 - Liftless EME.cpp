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

const int oo = 1e9, mxn = 4010;

int memo[mxn];
vii g[mxn];

int shortestPath(int u) {
	if (g[u].size() == 0) return 0;
	if (memo[u] != -1) return memo[u];
	int ans = oo;
	fori(i, 0, g[u].size()) {
		ii v = g[u][i];
		ans = min(ans, shortestPath(v.first) + v.second);
	}
	return memo[u] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string cs;
	while (cin >> cs) {
		fori(i, 0, mxn) g[i].clear();
		cout << cs << endl;
		int n, m; cin >> n >> m;
		fori(f, 0, n - 1) {
			fori(i, 0, m) {
				fori(j, 0, m) {
					int x; cin >> x;
					g[m * f + i].push_back(ii(m * (f + 1) + j, x + 2));
				}
			}
		}
		/*fori(i, 0, m * (n - 1)) {
			cout << i << " -> ";
			fori(j, 0, g[i].size())
				cout << g[i][j].first << " ";
			cout << endl;
		}
		cout << endl;*/
		memset(memo, -1, sizeof memo);
		int ans = oo;
		fori(i, 0, m)
			ans = min(ans, shortestPath(i));
		cout << ans << endl;
	}
	return 0;
}