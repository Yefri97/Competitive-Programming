#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	if (k == 2) {
		int a = 0, b = 0;
		fori(i, 0, n) {
			a += (s[i] != 'A' + i % 2);
			b += (s[i] != 'A' + (i + 1) % 2);
		}
		cout << min(a, b) << endl;
		fori(i, 0, n)
			cout << (char)('A' + (i + (b < a)) % 2);
		cout << endl;
	} else {
		int l = 0, r = 0, ans = 0;
		while (r < n) {
			char c = s[l], nc = '$';
			while (s[r] == c) r++;
			if ((r - l) % 2) {
				nc = 'A' + (c == 'A');
			} else {
				vi taken(k);
				if (r < n) taken[s[r] - 'A'] = 1;
				taken[s[r - 1] - 'A'] = 1;
				char cc = 0;
				while (taken[cc]) cc++;
				nc = cc + 'A';
			}
			for (int i = l + 1; i < r; i += 2) {
				s[i] = nc;
				ans++;
			}
			l = r;
		}
		cout << ans << endl;
		cout << s << endl;
	}
	return 0;
}