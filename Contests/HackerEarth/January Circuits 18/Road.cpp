#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 60, MN = 1e5 + 10;

int n, A[MN], memo[MN][MX];
vi P[MX];

int go(int id, int k) {
	if (memo[id][k] != -1) return memo[id][k];
	int ans = 0;
	for (int i = 0; i <= 50; i++) {
		auto it = upper_bound(P[i].begin(), P[i].end(), id);
		if (it == P[i].end() || abs(A[id] - i) > k) continue;
		int pos = *it;
		ans = max(ans, go(pos, k - abs(A[id] - i)));
	}
	return memo[id][k] = ans + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k; cin >> n >> k;
	fori(i, 0, n) {
		int x; cin >> x;
		A[i] = x;
		P[x].push_back(i);
	}
	memset(memo, -1, sizeof memo);
	int ans = go(0, k);
	cout << ans << endl;
	return 0;
}