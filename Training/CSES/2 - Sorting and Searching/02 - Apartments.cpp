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
 
const int oo = 1e9;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	fori(i, 0, n) cin >> a[i];
	fori(i, 0, m) cin >> b[i];
	sort(all(a)); sort(all(b));
	int ans = 0;
	int pt1 = 0, pt2 = 0;
	while (pt1 < n) {
		while (pt2 < m && b[pt2] < a[pt1] - k)
			pt2++;
		if (pt2 == m) break;
		if (b[pt2] <= a[pt1] + k) {
			ans++;
			pt2++;
		}
		pt1++;
	}
	cout << ans << endl;
	return 0;
}