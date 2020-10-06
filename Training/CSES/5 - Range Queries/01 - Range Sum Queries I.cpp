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
	int n, m; cin >> n >> m;
	vector<ll> a(n + 1);
	fori(i, 0, n) cin >> a[i + 1];
	fori(i, 1, n + 1) a[i] += a[i - 1];
	while (m--) {
		int l, r; cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}
	return 0;
}
