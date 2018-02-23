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

const int oo = 1e9, mxn = 110;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		vi freq(mxn);
		int n; cin >> n;
		fori(i, 0, n) {
			fori(j, 0, n) {
				int x; cin >> x;
				freq[x]++;
			}
		}
		bool ans = false;
		fori(i, 0, mxn)
			ans |= (freq[i] > n);
		cout << "Case " << ++cs << ": ";
		cout << (ans ? "no" : "yes") << endl;
	}
	return 0;
}