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

const int oo = 1e9, mxn = 1010;

int cnt[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int acc = 0;
	fori(i, 0, n) {
		int x; cin >> x;
		cnt[x]++;
		acc += x;
	}
	int ans = acc;
	fori(i, 1, mxn)
		ans = min(ans, acc - cnt[i] * i);
	cout << ans << endl;
	return 0;
}