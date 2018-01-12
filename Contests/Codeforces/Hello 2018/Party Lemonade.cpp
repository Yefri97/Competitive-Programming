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

const int oo = 1e9, MX = 35;

ll val[MX], sum[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	ll L; cin >> L;
	
	fori(i, 0, n)
		cin >> val[i];

	fori(i, 1, n)
		val[i] = min(val[i], val[i - 1] << 1);
	fori(i, n, 31)
		val[i] = val[i - 1] << 1;

	fori(i, 1, 31) {
		sum[i] = sum[i - 1];
		if ((L >> (i - 1)) & 1)
			sum[i] += val[i - 1];
	}

	ll acc = 0;
	fori(i, 0, 31)
		if ((L >> i) & 1)
			acc += val[i];

	ll ans = acc;
	for (int i = 30; i >= 0; i--)
		if (!(L >> i & 1) && (val[i] < sum[i]))
			ans = min(ans, acc - sum[i] + val[i]);

	cout << ans << endl;

	return 0;
}