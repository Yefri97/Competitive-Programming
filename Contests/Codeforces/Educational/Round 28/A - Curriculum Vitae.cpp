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

const int oo = 1e9, mxn = 100;

int A[mxn], zeros[mxn], ones[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		fori(i, 0, n)
			cin >> A[i];
		zeros[0] = 1 - A[0];
		ones[n - 1] = A[n - 1];
		fori(i, 1, n) {
			zeros[i] = zeros[i - 1] + (1 - A[i]);
			ones[n - i - 1] = ones[n - i] + (A[n - i - 1]);
		}
		int ans = 0;
		ans = max(ans, ones[0]);
		fori(i, 0, n - 1)
			ans = max(ans, zeros[i] + ones[i + 1]);
		ans = max(ans, zeros[n - 1]);
		cout << ans << endl;
	}
	return 0;
}