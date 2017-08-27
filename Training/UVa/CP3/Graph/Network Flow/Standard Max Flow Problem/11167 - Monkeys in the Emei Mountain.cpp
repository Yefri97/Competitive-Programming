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

const int oo = 1e9, mxn = 310, len = 5e4 + 10;

vi A[len], mark[len];
vii ans[mxn];
int n, res[mxn][mxn], p[mxn], f, s, t;

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
			fori(v, 0, n) {
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

bool find(vector<int> &v, int x) { return find(v.begin(), v.end(), x) != v.end(); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	s = 0;
	int m, k, cs = 0;
	while (cin >> m >> k && m) {
		memset(res, 0, sizeof res);
		fori(i, 0, len) A[i].clear();
		n = 1;
		int total = 0;
		fori(i, 0, m) {
			int v, a, b; cin >> v >> a >> b;
			res[s][i+1] += v;
			total += v;
			fori(j, a, b)
				A[j].push_back(i+1);
			n++;
		}
		vii intervals;
		int l = 0, r = 0;
		while (r < len) {
			l = r;
			while (r + 1 < len && A[r] == A[r + 1]) r++;
			fori(i, 0, A[r].size())
				res[A[r][i]][n] += r - l + 1;
			intervals.push_back(ii(l, r));
			n++;
			r++;
		}
		n++;
		t = n - 1;
		fori(i, m + 1, n - 1)
			res[i][t] += k * (intervals[i - m - 1].second - intervals[i - m - 1].first + 1);
		int mf = maxFlow();
		cout << "Case " << ++cs << ": ";
		if (total == mf) {
			cout << "Yes" << endl;
			fori(i, 0, len) mark[i].clear();
			fori(i, 0, n - m) {
				int it = 0, l = intervals[i].first, lenint = intervals[i].second - intervals[i].first + 1;
				fori(j, 0, m) {
					if (res[i + m + 1][j + 1] > 0) {
						int f = res[i + m + 1][j + 1];
						while (f--) {
							mark[l + it].push_back(j);
							it = (it + 1) % lenint;
						}
					}
				}
			}
			fori(i, 0, m) ans[i].clear();
			fori(i, 0, m) {
				int l = 0, r = 0;
				while (r < len && !find(mark[r], i)) r++;
				while (r < len) {
					l = r;
					while (r + 1 < len && find(mark[r], i) && find(mark[r+1], i))
						r++;
					ans[i].push_back(ii(l, r + 1));
					r++;
					while (r < len && !find(mark[r], i)) r++;
				}
			}
			fori(i, 0, m) {
				cout << ans[i].size();
				fori(j, 0, ans[i].size())
					cout << " (" << ans[i][j].first << "," << ans[i][j].second << ")";
				cout << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}