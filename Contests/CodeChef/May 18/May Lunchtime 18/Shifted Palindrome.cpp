#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 400010, MD = 999999937, kP = 161259101;

ll pw[MN];
ll h1[MN], h2[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	pw[0] = 1;
	fori(i, 1, MN)
		pw[i] = (pw[i - 1] * kP) % MD;
	int t; cin >> t;
	while (t--) {
		string s; cin >> s; s += s;
		int n = s.size();
		h1[0] = s[0] - 'a';
		h2[n - 1] = s[n - 1] - 'a';
		for (int i = 1, j = n - 2; i < n; i++, j--) {
			h1[i] = (h1[i - 1] + (s[i] - 'a') * pw[i]) % MD;
			h2[j] = (h2[j + 1] + (s[j] - 'a') * pw[i]) % MD;
		}
		int ans = 0;
		fori(i, 0, n / 2) {
			int l = i, r = i + n / 2 - 1;
			ll a = (h1[r] - (l > 0 ? h1[l - 1] : 0) + MD) % MD;
			ll b = (h2[l] - (r + 1 < n ? h2[r + 1] : 0) + MD) % MD;
			ans += ((a * pw[n - r - 1]) % MD == (b * pw[l]) % MD);
		}
		cout << ans << endl;
	}
	return 0;
}
