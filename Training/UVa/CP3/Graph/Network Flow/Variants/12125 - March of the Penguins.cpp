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

const int oo = 1e9, mxn = 2 * 100 + 10;

int V, res[mxn][mxn], p[mxn], f, s, t;

void augment(int v, int minEdge) {
	if (v == s) { f = minEdge; return; }
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int maxFlow() {
	int mf = 0;
	while (true) {
		f = 0;
		
		vi dist(mxn, oo); dist[s] = 0;
		queue<int> q; q.push(s);
		memset(p, -1, sizeof p);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			fori(v, 0, V) {
				if (res[u][v] > 0 && dist[v] == oo) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, oo);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

int buff[mxn][mxn];
double X[110], Y[110];

int in(int x) { return (x << 1); }
int out(int x) { return (x << 1) + 1; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	while (cs--) {
		memset(buff, 0, sizeof buff);
		int n; cin >> n;
		double d; cin >> d;
		int total = 0;
		V = 2 * n + 2;
		s = V - 2;
		t = V - 1;
		fori(i, 0, n) {
			int p, w; cin >> X[i] >> Y[i] >> p >> w;
			buff[s][in(i)] = p;
			buff[in(i)][out(i)] = w;
			total += p;
		}
		fori(u, 0, n) {
			fori(v, 0, u) {
				if (sqrt(sq(X[u] - X[v]) + sq(Y[u] - Y[v])) <= d) {
					buff[out(v)][in(u)] = oo;
					buff[out(u)][in(v)] = oo;
				}
			}
		}
		vi ans;
		fori(i, 0, n) {
			memcpy(res, buff, sizeof res);
			res[in(i)][t] = oo;
			int mf = maxFlow();
			if (mf == total)
				ans.push_back(i);
		}
		if (ans.empty()) {
			cout << -1 << endl;
		} else {
			cout << ans[0];
			fori(i, 1, ans.size())
				cout << " " << ans[i];
			cout << endl;
		}
	}
	return 0;
}