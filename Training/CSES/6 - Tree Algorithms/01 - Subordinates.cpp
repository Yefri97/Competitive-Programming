#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const int MN = 200010;

int cnt[MN];
vector<int> g[MN];

void dfs(int u) {
	cnt[u] = 1;
	for (int v : g[u]) {
		dfs(v);
		cnt[u] += cnt[v];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	fori(i, 1, n) {
		int p; cin >> p; p--;
		g[p].push_back(i);
	}
	dfs(0);
	fori(i, 0, n)
		cout << cnt[i] - 1 << " ";
	cout << endl;
	return 0;
}
