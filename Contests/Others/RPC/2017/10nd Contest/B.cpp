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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi A(n);
		fori(i, 0, n)
			cin >> A[i];
		vi lis1(n, 1), lis2(n, 1);
		fori(i, 0, n) {
			fori(j, 0, i) {
				if (A[j] < A[i])
					lis1[i] = max(lis1[i], lis1[j] + 1);
				if (A[n - j - 1] < A[n - i - 1])
					lis2[n - i - 1] = max(lis2[n - i - 1], lis2[n - j - 1] + 1);
			}
		}
		fori(i, 1, n) {
			lis1[i] = max(lis1[i], lis1[i - 2]);
			lis2[n - i - 1] = max(lis2[n - i - 1], lis2[n - i]);
		}
		int ans = lis2[0];
		fori(i, 0, n - 1)
			ans = max(ans, lis1[i] + lis2[i + 1]);
		ans = max(ans, lis1[n - 1]);
		cout << ans << endl;
	}
	return 0;
}