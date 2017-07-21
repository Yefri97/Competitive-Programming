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

const int oo = 1e9, mxn = 2510;

int n;
vi g[mxn], cnt;

void bfs(int s) {
	vi dist(n, oo); dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fori(i, 0, g[u].size()) {
			int v = g[u][i];
			if (dist[v] == oo) {
				dist[v] = dist[u] + 1;
				cnt[dist[v]]++;
				q.push(v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	fori(i, 0, n) {
		int k; cin >> k;
		while (k--) {
			int x; cin >> x;
			g[i].push_back(x);
		}
	}
	int t; cin >> t;
	while (t--) {
		int s; cin >> s;
		cnt.assign(n, 0);
		bfs(s);
		int m = 0, d = 0;
		fori(i, 0, n) {
			if (cnt[i] > m) {
				m = cnt[i];
				d = i;
			}
		}
		if (d == 0)
			cout << 0 << endl;
		else
			cout << m << " " << d << endl;
	}
	return 0;
}