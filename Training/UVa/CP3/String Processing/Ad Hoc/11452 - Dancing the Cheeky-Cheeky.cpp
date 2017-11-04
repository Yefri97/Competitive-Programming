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
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int l = 1, n = s.size();
		while (true) {
			string patt = s.substr(0, l);
			bool b = true;
			for (int i = l; i + l < n; i += l)
				b &= s.substr(i, l) == patt;
			if (b) break;
			l++;
		}
		int m = n % l;
		fori(i, 0, 8)
			cout << s[(m + i) % l];
		cout << "..." << endl;
	}
	return 0;
}