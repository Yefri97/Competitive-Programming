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

const int oo = 1e9, MX = 5010, MD = 1e9 + 7;

int n;
char A[MX];
int memo[MX][MX];

int dp(int id, int ident) {
	if (id == n) return 1;
	if (memo[id][ident] != -1) return memo[id][ident];
	int ans = 0;
	if (ident > 0 && A[id - 1] != 'f') ans = (ans + dp(id, ident - 1)) % MD;
	if (A[id] == 'f')
		ans = (ans + dp(id + 1, ident + 1)) % MD;
	else
		ans = (ans + dp(id + 1, ident)) % MD;
	return memo[id][ident] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	memset(memo, -1, sizeof memo);
	int ans = dp(0, 0);
	cout << ans << endl;
	return 0;
}