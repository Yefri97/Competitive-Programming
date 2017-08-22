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

const int INF = 1e9, MAXN = 4010;

int coins[5], memo[MAXN];

int solver(int x) {
	if (x == 0) return 0;
	if (memo[x] != -1) return memo[x];
	int ans = -INF;
	fori(i, 0, 3)
		if (x - coins[i] >= 0)
			ans = max(ans, solver(x - coins[i]) + 1);
	return memo[x] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, 3)
		cin >> coins[i];
	memset(memo, -1, sizeof memo);
	int ans = solver(n);
	cout << ans << endl;
	return 0;
}