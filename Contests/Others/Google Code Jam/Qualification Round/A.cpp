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
	int tc; cin >> tc;
	fori(t, 0, tc) {
		int d; cin >> d;
		string s; cin >> s;
		int n = s.size();
		int cnt = 0;
		fori(i, 0, n) cnt += (s[i] == 'S');
		cout << "Case #" << t + 1 << ": ";
		if (cnt > d) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			vi f(32);
			int c = 0;
			fori(i, 0, n) {
				if (s[i] == 'C') c++;
				else f[c]++;
			}
			int ans = 0, sum = 0;
			fori(i, 0, 32) sum += (f[i] << i);
			while (sum > d) {
				while (f[c] == 0) c--;
				sum -= (1 << (c - 1));
				f[c]--;
				f[c - 1]++;
				ans++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
