#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 310;

int A[MN][MN], f[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
	    fori(j, 0, n)
	        cin >> A[i][j];
	int ans = 0, total = 0;
	fori(i, 0, 2 * n) {
	    total -= f[i % n];
	    f[i] = 0;
	    fori(j, 0, n) {
	        total += A[i % n][j];
	        f[j] += A[i % n][j];
	    }
	    ans = max(ans, total);
	}
	cout << ans << endl;
	return 0;
}
