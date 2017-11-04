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

bool check(string a, string b) {
	if (b.size() > a.size())
		swap(a, b);
	int n = a.size(), m = b.size();
	int la = 0, lb = 0;
	while (lb < m && a[la] == b[lb]) la++, lb++;
	int ra = n - 1, rb = m - 1;
	while (rb >= lb && a[ra] == b[rb]) ra--, rb--;
	if (ra == la || ra - la == 1 && a[la] == b[rb] && a[ra] == b[lb]) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<string> dict(n);
	fori(i, 0, n)
		cin >> dict[i];
	int m; cin >> m;
	while (m--) {
		string q; cin >> q;
		if (find(dict.begin(), dict.end(), q) != dict.end()) {
			cout << q << " is correct" << endl;
		} else {
			string ans = "-1";
			fori(i, 0, n) {
				string w = dict[i];
				if (check(w, q)) { ans = w; break; }
			}
			if (ans != "-1")
				cout << q << " is a misspelling of " << ans << endl;
			else
				cout << q << " is unknown" << endl;
		}
	}
	return 0;
}