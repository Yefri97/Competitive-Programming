#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 5010;
int A[MAXN], dp[MAXN];
int fr[MAXN], ls[MAXN], was[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		ls[A[i]] = i;
	for (int i = n - 1; i >= 0; i--)
		fr[A[i]] = i;
	for (int i = 0; i < n; i++) {
		memset(was, 0, sizeof was);
		dp[i] = (i > 0) ? dp[i - 1] : 0;
		for (int j = i, l = i, r = i, curr = 0; j >= 0; j--) {
			l = min(l, fr[A[j]]);
			r = max(r, ls[A[j]]);
			if (!was[A[j]]) curr ^= A[j];
			was[A[j]] = true;
			if (j <= l && r <= i)
				dp[i] = max(dp[i], ((j > 0) ? dp[j - 1] : 0) + curr);
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}