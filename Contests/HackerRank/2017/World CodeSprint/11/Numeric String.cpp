#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define toint(C) (C-'0')

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int k, b, m; cin >> k >> b >> m;
	int window = 0, pw = 1;
	for (int i = k - 1; i >= 0; i--) {
		window = mod(window + toint(s[i]) * pw, m);
		pw = mod(pw * b, m);
	}
	int ans = window;
	fori(i, k, (int)s.size()) {
		window = mod(window * b - toint(s[i - k]) * pw + toint(s[i]), m);
		ans += window;
	}
	cout << ans << endl;
	return 0;
}