#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
const ll oo = 1e15;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	vi a(n);
	fori(i, 0, n) cin >> a[i];
	ll sum = 0, ans = -oo;
	fori(i, 0, n) {
		sum = max(sum, 0LL) + a[i];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}