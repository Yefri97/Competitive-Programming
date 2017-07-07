// Coin Change (CC)
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

const int INF = 1e9, MAXN = 1000010;
int A[MAXN], dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int p; cin >> p;
		int n; cin >> n;
		fori(i, 0, n)
			cin >> A[i];
		int acc = accumulate(A, A + n, 0);
		for (int i = 0; i <= acc; i++) dp[i] = INF;
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = acc; j >= 0; j--) {
				if (dp[j] < INF)
					dp[j + A[i]] = min(dp[j + A[i]], dp[j] + 1);
			}
		}
		int val = p;
		while (dp[val] == INF) val++;
		cout << val << " " << dp[val] << endl;
	}
	return 0;
}