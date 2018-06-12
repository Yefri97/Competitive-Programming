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
typedef pair<int, string> ii;
typedef pair<int, ii> iii;

const int oo = 1e9, mxn = 500010;

int n, dp[mxn];
map<string, int> mapper;
string names[mxn];
vi g[mxn];

int go(int u) {
	if (dp[u] != -1) return dp[u];
	int ans = 0;
	fori(i, 0, g[u].size())
		ans = max(ans, go(g[u][i]));
	return dp[u] = ans + 1;
}

int getId(string s) {
	if (mapper.count(s) == 0) {
		names[n] = s;
		mapper[s] = n++;
	}
	return mapper[s];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m;
	while (cin >> m) {
		n = 0;
		fori(i, 0, mxn) g[i].clear();
		mapper.clear();
		fori(i, 0, m) {
			string a, b; cin >> a >> b;
			int u = getId(a), v = getId(b);
			g[v].push_back(u);
		}
		memset(dp, -1, sizeof dp);
		fori(i, 0, n)
			go(i);
		vector<iii> ans;
		fori(i, 0, n)
			ans.push_back(iii(dp[i], ii(g[i].size(), names[i])));
		sort(ans.begin(), ans.end());
		fori(i, 0, n)
			cout << ans[i].first << "." << ans[i].second.first << " " << ans[i].second.second << endl;
	}
	return 0;
}