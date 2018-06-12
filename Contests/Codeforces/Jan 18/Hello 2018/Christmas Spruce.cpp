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

const int oo = 1e9, MX = 1000;

vector<int> g[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 1, n) {
		int p; cin >> p; p--;
		g[p].push_back(i);
	}
	int ans = 1;
	fori(u, 0, n) {
		if (g[u].size() == 0) continue;
		int cnt = 0;
		for (int v : g[u])
			cnt += (g[v].size() == 0);
		ans &= cnt >= 3;
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}