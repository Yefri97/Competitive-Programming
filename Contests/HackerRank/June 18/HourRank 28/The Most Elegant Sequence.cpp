#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int n, q;
int a[20], f[20][10];
int c[10], mx[2000000];
int dp[2000000][20];

void precalc(int mask, int id) {
	if (id == n) return;
	precalc(mask, id + 1);
	fori(i, 0, 10)
		c[i] += f[id][i];
	mx[mask | (1 << id)] = *max_element(c, c + 10);
	precalc(mask | (1 << id), id + 1);
	fori(i, 0, 10)
		c[i] -= f[id][i];
}

int solve(int mask, int id) {
	if (mask == (1 << n) - 1) return 0;
	if (dp[mask][id] != -1) return dp[mask][id];
	int ans = 0;
	fori(i, 0, n) if (((mask >> i) & 1) == 0) {
		if (mx[mask | (1 << i)] > q) continue;
		ans = max(ans, solve(mask | (1 << i), i) + (a[i] ^ a[id]));
	}
	return dp[mask][id] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	fori(i, 0, n)
		cin >> a[i];
	fori(i, 0, n) {
		string s; cin >> s;
		for (char c : s)
			f[i][c - '0']++;
	}
	precalc(0, 0);
	memset(dp, -1, sizeof dp);
	int ans = 0;
	fori(i, 0, n) {
		if (mx[1 << i] > q) continue;
		ans = max(ans, solve((1 << i), i) + a[i]);
	}
	cout << ans << endl;
	return 0;
}
