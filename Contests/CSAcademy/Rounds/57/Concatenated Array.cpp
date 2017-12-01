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

int solver(string s) {
	int ans = -1, len = 0;
	for (char c : s) {
		if (c == '0')
			len++;
		else
			len = 0;
		ans = max(ans, len);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	int f = 0;
	for (char c : s)
		f |= (c == '1');
	ll ans = 0;
	if (f) {
		if (k == 1)
			ans = solver(s);
		else
			ans = solver(s + s);
	} else {
		ans = n * k;
	}
	cout << ans << endl;
	return 0;
}