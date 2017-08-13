#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s;
		fori(i, 1, n+1)
			s += to_string(i);
		vi cnt(10, 0);
		for (char c : s)
			cnt[c-'0']++;
		fori(i, 0, 9)
			cout << cnt[i] << " ";
		cout << cnt[9] << endl;
	}
	return 0;
}