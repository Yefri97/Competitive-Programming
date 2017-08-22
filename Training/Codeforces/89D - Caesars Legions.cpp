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

const int oo = 1e9, mxn = 210, kmod = 1e8;

int n1, n2, k1, k2;
int memo[210][110];

int solver(int id, int f) {
	if (id > n1 + n2) return 0;
	if (id == n1 + n2) return f == 0;
	if (id + f == n1 + n2) return f <= k1;
	if (memo[id][f] != -1) return memo[id][f];
	int ans = 0;
	for (int i = 1; i <= k1; i++)
		for (int j = 1; j <= k2; j++)
			ans = (ans + solver(id + i + j, f - i)) % kmod;
	return memo[id][f] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n1 >> n2 >> k1 >> k2;
	memset(memo, -1, sizeof memo);
	int ans = 0;
	for (int i = 0; i <= min(n2, k2); i++)
		ans = (ans + solver(i, n1)) % kmod;
	cout << ans << endl;
	return 0;
}