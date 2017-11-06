#include <bits/stdc++.h>
//#define endl '\n'
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

const int oo = 1e9, MX = 100;

int val[MX][MX], memo[MX][MX];

int f(string s) {
	for (int l = 1; l <= s.size(); l++) {
		string ss = s.substr(0, l);
		bool b = true;
		for (int i = 0; i < s.size(); i += l)
			b &= (i + l <= s.size() && ss == s.substr(i, l));
		if (b) return l;
	}
	return -1;
}

int dp(int l, int r) {
	if (r < l) return 0;
	if (l == r) return 1;
	if (memo[l][r] != -1) return memo[l][r];
	int ans = oo;
	for (int i = l + 1; i <= r; i++)
		ans = min(ans, dp(l, i - 1) + dp(i, r));
	int k = val[l][r], m = r - l + 1;
	if (k != m)
		ans = min(ans, dp(l, l + k - 1));
	return memo[l][r] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while (cin >> s && s != "*") {
		int n = s.size();
		for (int l = 1; l <= n; l++)
			for (int i = 0; i + l <= n; i++) 
				val[i][i + l - 1] = f(s.substr(i, l));
		memset(memo, -1, sizeof memo);
		int ans = dp(0, n - 1);
		cout << ans << endl;
	}
	return 0;
}