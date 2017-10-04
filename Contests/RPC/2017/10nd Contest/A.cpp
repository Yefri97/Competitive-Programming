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

const int oo = 1e9, mxn = 1010;

map<char, int> mapper = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

int memo[mxn];
vi g[mxn];

int go(int u) {
	if (g[u].size() == 0) return 1;
	if (memo[u] != -1) return memo[u];
	int ans = 0;
	fori(i, 0, g[u].size())
		ans = max(ans, go(g[u][i]));
	return memo[u] = ans + 1;
}

vi build(string s) {
	vi freq(4);
	for (char c : s)
		freq[mapper[c]]++;
	return freq;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		fori(i, 0, n + 1) g[i].clear();
		vvi prefix(n + 1), postfix(n + 1);
		fori(i, 0, n + 1) {
			string s; cin >> s;
			prefix[i] = build(s.substr(0, k));
			postfix[i] = build(s.substr(s.size() - k, k));
		}
		fori(i, 0, n + 1)
			fori(j, i + 1, n + 1)
				if (postfix[i] == prefix[j])
					g[i].push_back(j);
		memset(memo, -1, sizeof memo);
		int ans = go(0);
		cout << ans - 1 << endl;
	}
	return 0;
}