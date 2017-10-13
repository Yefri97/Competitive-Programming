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


double logComb(int n, int k) {
	if (k > n - k)
		k = n - k;
	double ans = 0;
	for (int i = 1; i <= k; i++, n--) {
		ans += log10(n);
		ans -= log10(i);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	while (cin >> n >> k) {
		int ans = floor(logComb(n, k)) + 1;
		cout << ans << endl;
	}
	return 0;
}