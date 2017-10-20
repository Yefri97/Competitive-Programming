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

const int oo = 1e9, mxn = 1010;

int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x;
	while (cin >> x && x) {
		int n = 0;
		A[n++] = x;
		while (cin >> x && x)
			A[n++] = x;
		int min_val = *min_element(A, A + n);
		fori(i, 0, n)
			A[i] -= min_val;
		int ans = 0;
		fori(i, 0, n)
			ans = __gcd(ans, A[i]);
		cout << ans << endl;
	}
	return 0;
}