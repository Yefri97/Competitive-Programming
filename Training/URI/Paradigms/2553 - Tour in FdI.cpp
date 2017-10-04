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

const int oo = 1e9, mxn = 45;

int n, g[mxn], y[mxn], memo[40][40 * 20][40 * 20];

int solver(int id, int currg, int curry) {
	if (id == n) return 0;
	if (memo[id][currg][curry] != -1) return memo[id][currg][curry];
	if ((g[id] < 0 && currg + g[id] < 0) || (y[id] < 0 && curry + y[id] < 0))
		return memo[id][currg][curry] = solver(id + 1, currg, curry);
	return memo[id][currg][curry] = max(solver(id + 1, currg, curry), solver(id + 1, currg + g[id], curry + y[id]) + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n) {
		int a, b; cin >> a >> b;
		fori(i, 0, n)
			cin >> g[i] >> y[i];
		memset(memo, -1, sizeof memo);
		int ans = solver(0, a, b);
		cout << ans << endl;
	}
	return 0;
}