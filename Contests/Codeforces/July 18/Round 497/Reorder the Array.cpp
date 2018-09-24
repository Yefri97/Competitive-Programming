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
	int n; cin >> n;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for (int l = 0, r = 0; r < n; l++) {
		while (r < n && a[r] <= a[l]) r++;
		ans += (r < n);
		r++;
	}
	cout << ans << endl;
	return 0;
}
