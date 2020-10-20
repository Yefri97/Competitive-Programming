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
	int n; cin >> n;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	int ans = 0;
	set<int> dict;
	int l = 0, r = 0;
	while (r < n) {
		while (l < r && dict.count(a[r]))
			dict.erase(a[l++]);
		ans = max(ans, r - l + 1);
		dict.insert(a[r++]);
	}
	cout << ans << endl;
	return 0;
}
