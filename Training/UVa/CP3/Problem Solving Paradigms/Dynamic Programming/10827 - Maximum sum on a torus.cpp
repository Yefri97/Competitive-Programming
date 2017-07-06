// Max 2D Range Sum
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

const int INF = 1e9, MAXN = 300;
int A[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n) {
			fori(j, 0, n) {
				cin >> A[i][j];
				A[i][n + j] = A[n + i][n + j] = A[n + i][j] = A[i][j];
			}
		}
		int m = n * 2;
		fori(i, 0, m) {
			fori(j, 0, m) {
				if (i > 0) A[i][j] += A[i - 1][j];
				if (j > 0) A[i][j] += A[i][j - 1];
				if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
			}
		}
		int ans = -INF;
		fori(i, 0, n) fori(j, 0, n) {
			fori(h, 0, n) fori(w, 0, n) {
				int subrect = 0;
				subrect += A[i + h][j + w];
				if (i > 0) subrect -= A[i - 1][j + w];
				if (j > 0) subrect -= A[i + h][j - 1];
				if (i > 0 && j > 0) subrect += A[i - 1][j - 1];
				ans = max(ans, subrect);
			}
		}
		cout << ans << endl;
	}
	return 0;
}