#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, m, a, b; cin >> n >> m >> a >> b;
	n %= m;
	ll ans = min((m - n) * a, n * b);
	cout << ans << endl;
	return 0;
}
