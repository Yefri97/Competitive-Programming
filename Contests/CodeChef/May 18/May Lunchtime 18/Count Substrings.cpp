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
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int k; cin >> k;
		int n = s.size();
		int ans = 0;
		fori(i, 0, n) {
			int cnt = 0;
			vi d(26), f(n);
			fori(j, i, n) {
				int c = s[j] - 'a';
				if (d[c] == 0) cnt++;
				else f[d[c]]--;
				d[c]++;
				f[d[c]]++;
				ans += (cnt >= k && f[d[c]] == cnt);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
