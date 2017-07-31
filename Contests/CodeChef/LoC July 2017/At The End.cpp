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

const int oo = 1e9, mxn = 100010;

int n;
int memo[mxn];
string s;
vi ocurr[30];

int solver(int pos) {
	if (pos == n - 1) return 0;
	if (memo[pos] != -1) return memo[pos];
	int ch = s[pos] - 'a';
	int i = upper_bound(ocurr[ch].begin(), ocurr[ch].end(), pos) - ocurr[ch].begin();
	if (i == ocurr[ch].size()) return memo[pos] = solver(pos + 1) + abs(s[pos] - s[pos + 1]);
	return memo[pos] = min(solver(pos + 1) + abs(s[pos] - s[pos + 1]), solver(ocurr[ch][i]));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		fori(i, 0, 26) ocurr[i].clear();
		cin >> s;
		n = s.size();
		fori(i, 0, n)
			ocurr[s[i]-'a'].push_back(i);
		memset(memo, -1, sizeof memo);
		int ans = solver(0);
		cout << ans << endl;
	}
	return 0;
}