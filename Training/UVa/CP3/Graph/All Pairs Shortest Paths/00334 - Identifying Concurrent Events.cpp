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

const int oo = 1e9, mxn = 410;

string names[mxn];
int g[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, cs = 0;
	while (cin >> n && n) {
		memset(g, 0, sizeof g);
		int id = 0;
		map<string, int> mapper;
		fori(i, 0, n) {
			int k; cin >> k;
			while (k--) {
				string s; cin >> s;
				if (k) g[id][id + 1] = 1;
				names[id] = s;
				mapper[s] = id++;
			}
		}
		int m; cin >> m;
		while (m--) {
			string a, b; cin >> a >> b;
			g[mapper[a]][mapper[b]] = 1;
		}
		/*fori(i, 0, id) {
			fori(j, 0, id)
				cout << g[i][j];
			cout << endl;
		}*/
		fori(k, 0, id)
			fori(i, 0, id)
				fori(j, 0, id)
					g[i][j] |= (g[i][k] & g[k][j]);
		vii ans;
		fori(i, 0, id)
			fori(j, 0, i)
				if (g[i][j] == 0 && g[j][i] == 0)
					ans.push_back(ii(j, i));
		cout << "Case " << ++cs << ", ";
		if (ans.size()) {
			cout << ans.size() << " concurrent events:" << endl;
			fori(i, 0, min(2, (int)ans.size()))
				cout << "(" << names[ans[i].first] << "," << names[ans[i].second] << ") ";
			cout << endl;
		} else {
			cout << "no concurrent events." << endl;
		}
	}
	return 0;
}