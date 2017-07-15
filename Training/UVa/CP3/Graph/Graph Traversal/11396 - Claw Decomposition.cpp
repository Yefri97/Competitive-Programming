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

const int oo = 1e9, mxn = 310;

vi g[mxn];
int color[mxn];

bool bgc(int s) {
	queue<int> q; q.push(s);
	color[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if (color[v] == -1) {
				color[v] = 1 - color[u];
				q.push(v);
			} else if (color[v] == color[u]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n) {
		fori(i, 0, n) g[i].clear();
		int a, b;
		while (cin >> a >> b && a) {
			a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		memset(color, -1, sizeof color);
		bool ans = true;
		fori(u, 0, n)
			if (color[u] == -1)
				ans &= bgc(u);
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}