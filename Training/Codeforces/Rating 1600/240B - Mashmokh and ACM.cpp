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

const int oo = 1e9, mxn = 2010, kmod = 1e9 + 7;

int n, k;
int memo[mxn][mxn];

int solver(int id, int x) {
	if (id == k) return 1;
	if (memo[id][x] != -1) return memo[id][x];
	int ans = 0;
	for (int i = 1; i * x <= n; i++)
		ans = (ans + solver(id + 1, i * x)) % kmod;
	return memo[id][x] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	memset(memo, -1, sizeof memo);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + solver(1, i)) % kmod;
	cout << ans << endl;
	return 0;
}