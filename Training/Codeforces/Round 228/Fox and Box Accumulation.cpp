#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MX = 101;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi v(n), f(MX);
	fori(i, 0, n)
		cin >> v[i];
	sort(v.begin(), v.end());
	v[0] = 0;
	int ans = 0;
	for (int i = 0, idx; i < n; i++) {
		if (idx > v[i]) {
			idx = 1;
			f[idx]++;
			ans++;
		} else {
			f[idx]--; f[idx + 1]++;
			if (f[idx] == 0) idx++;
		}
	}
	cout << ans << endl;
	return 0;
}
