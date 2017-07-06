// Max 1D Range Sum
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

const int INF = 1e9, MAXN = 25;
int p, n, m;
ll A[MAXN][MAXN][MAXN], board[MAXN][MAXN];

ll max2Drange() {
	fori(j, 0, m)
		fori(i, 1, n)
			board[i][j] += board[i - 1][j];
	ll ans = -1e15;
	fori(a, 0, n)
		fori(b, 0, a + 1) {
			ll sum = 0;
			fori(j, 0, m) {
				sum += board[a][j] - (b == 0 ? 0 : board[b - 1][j]);
				ans = max(ans, sum);
				if (sum < 0) sum = 0;
			}
		}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> p >> n >> m;
		fori(k, 0, p)
			fori(i, 0, n)
				fori(j, 0, m)
					cin >> A[k][i][j];
		fori(i, 0, n)
			fori(j, 0, m)
				fori(k, 1, p)
					A[k][i][j] += A[k - 1][i][j];
		ll ans = -1e15;
		fori(a, 0, p) {
			fori(b, 0, a + 1) {
				fori(i, 0, n)
					fori(j, 0, m)
						board[i][j] = A[a][i][j] - (b == 0 ? 0 : A[b - 1][i][j]);
				ans = max(ans, max2Drange());
			}
		}
		cout << ans << endl;
		if (t) cout << endl;
	}
	return 0;
}