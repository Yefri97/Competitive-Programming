// Non Classical (The Easiser Ones)
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int n, m;
ll memo[60][60];

ll solver(int id, int k) {
	if (id == n) return k == 0;
	if (k == 0 || id > n) return 0;
	if (memo[id][k] != -1) return memo[id][k];
	ll ans = 0;
	for (int i = 1; i <= m; i++)
		ans += solver(id + i, k - 1);
	return memo[id][k] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k;
	while (cin >> n >> k >> m) {
		memset(memo, -1, sizeof memo);
		ll ans = solver(0, k);
		cout << ans << endl;
	}
	return 0;
}