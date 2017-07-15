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

const int oo = 1e9, mxn = 110;

int in[mxn];
string vs[mxn];
vi g[mxn];
map<string, int> mapper;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, cs = 0;
	while (cin >> n) {
		fori(i, 0, n) {
			string s; cin >> s;
			vs[i] = s;
			mapper[s] = i;
		}
		fori(i, 0, n) g[i].clear();
		memset(in, 0, sizeof in);
		int m; cin >> m;
		fori(i, 0, m) {
			string sa, sb; cin >> sa >> sb;
			int a = mapper[sa], b = mapper[sb];
			g[a].push_back(b);
			in[b]++;
		}
		priority_queue<int, vector<int>, greater<int> > pq;
		fori(u, 0, n) {
			if (in[u] == 0)
				pq.push(u);
		}
		cout << "Case #" << ++cs << ": Dilbert should drink beverages in this order:";
		while (!pq.empty()) {
			int u = pq.top(); pq.pop();
			fori(i, 0, g[u].size()) {
				int v = g[u][i];
				in[v]--;
				if (in[v] == 0)
					pq.push(v);
			}
			cout << " " << vs[u];
		}
		cout << "." << endl << endl;
	}
	return 0;
}