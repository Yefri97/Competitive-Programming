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
		vector<string> h(10);
		fori(i, 0, 10) {
			string s; cin >> s;
			h[i] = s;
		}
		int m = h[0].size();
		string ans;
		fori(j, 1, m - 1) {
			int c = 0;
			fori(i, 1, 9)
				c = 2 * c + (h[9 - i][j] == '\\');
			ans.push_back(c);
		}
		cout << ans << endl;
	}
	return 0;
}