// Longest Increasing Subsequence
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 2010;
int A[2 * MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n) {
			int x; cin >> x;
			A[n + i] = A[n - i - 1] = x;
		}
		vi lis(2 * n, 1);
		fori(i, 0, 2 * n)
			fori(j, 0, i)
				if (A[j] < A[i])
					lis[i] = max(lis[i], lis[j] + 1);
		int ans = 0;
		fori(i, 0, 2 * n)
			ans = max(ans, lis[i]);
		cout << ans << endl;
	}
	return 0;
}