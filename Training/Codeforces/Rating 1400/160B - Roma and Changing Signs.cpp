#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 100010;
int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n) {
		int x; cin >> x;
		if (x <= 0 && k)
			A[i] = -x, k--;
		else
			A[i] = x;
	}
	int ans = accumulate(A, A + n, 0);
	if (k > 0 && k % 2 == 1)
		ans -= 2 * (*min_element(A, A + n));
	cout << ans << endl;
	return 0;
}