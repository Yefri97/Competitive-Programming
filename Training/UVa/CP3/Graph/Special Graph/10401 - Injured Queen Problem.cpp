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

const int oo = 1e9, mxn = 20;

int n;
ll memo[mxn][mxn];
string line;

int getInt(char c) {
	if (isdigit(c)) return c - '0' - 1;
	return 10 + (c - 'A') - 1;
}

ll solver(int id, int last) {
	if (id == n) return 1;
	if (memo[id][last] != -1) return memo[id][last];
	ll ans = 0;
	if (line[id] == '?') {
		fori(i, 0, n)
			if (abs(i - last) > 1)
				ans += solver(id + 1, i);
	} else {
		int x = getInt(line[id]);
		if (abs(x - last) > 1)
			ans += solver(id + 1, x);
	}
	return memo[id][last] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> line) {
		n = line.size();
		memset(memo, -1, sizeof memo);
		ll ans = 0;
		if (line[0] == '?') {
			fori(i, 0, n)
				 ans += solver(1, i);
		} else {
			ans += solver(1, getInt(line[0]));
		}
		cout << ans << endl;
	}
	return 0;
}