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
	string s; cin >> s;
	int n = s.size();
	int ans = oo;
	fori(i, 0, n) {
		int cnt = 0;
		for (int l = i, r = n - 1; r > l; l++, r--)
			cnt += (s[l] != s[r]);
		ans = min(ans, i + cnt);
	}
	cout << ans << endl;
	return 0;
}