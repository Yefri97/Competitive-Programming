#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010, offset = MN;

int dp[MN];
int best[2 * MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi sum(n), large(n);
	fori(i, 0, n) {
		char a, b; cin >> a >> b;
		sum[i] = (a == 'A' ? 1 : -1);
		large[i] = (b == 'L' ? 1 : 0);
	}
	fori(i, 1, n)
		sum[i] += sum[i - 1];
	int l1 = -1, l2 = -1, mn = oo, mx = -oo;
	fori(r, 0, n) {
		if (large[r]) {
			l1 = l2;
			l2 = r;
			if (l1 == -1) { dp[r] = (sum[r] >= 0); continue; }
			mn = oo, mx = -oo;
			fori(i, l1, l2) {
				best[sum[i] + offset] = 0;
				mn = min(mn, sum[i]);
				mx = max(mx, sum[i]);
			}
			fori(i, l1, l2)
				best[sum[i] + offset] = max(best[sum[i] + offset], dp[i]);
			fori(i, mn + 1, mx + 1)
				best[i + offset] = max(best[i + offset], best[i - 1 + offset]);
		}
		if (mn < oo) {
			dp[r] = best[mx + offset];
			if (sum[r] >= mn)
				dp[r] = max(dp[r], best[min(mx, sum[r]) + offset] + 1);
		} else {
			dp[r] = (l2 == -1 ? 0 : (sum[r] >= 0));
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
