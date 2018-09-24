#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	s += s;
	int cnt = 1, ans = 1;
	fori(i, 1, SZ(s)) {
		if (s[i] != s[i - 1])
			cnt = min(cnt + 1, n);
		else
			cnt = 1;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
