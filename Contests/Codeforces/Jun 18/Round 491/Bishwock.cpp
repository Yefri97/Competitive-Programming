#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s1, s2; cin >> s1 >> s2;
	s1 = "XXX" + s1;
	s2 = "XXX" + s2;
	int n = s1.size();
	vi up(n), dw(n);
	fori(i, 0, n) {
		up[i] = (s1[i] == 'X');
		dw[i] = (s2[i] == 'X');
	}
	vi dp(n);
	fori(i, 3, n) {
		dp[i] = dp[i - 1];
		if (up[i - 1] + dw[i - 1] + up[i] + dw[i] < 2)
			dp[i] = max(dp[i], dp[i - 2] + 1);
		if (up[i - 2] + dw[i - 2] + up[i - 1] + dw[i - 1] + up[i] + dw[i] == 0)
			dp[i] = max(dp[i], dp[i - 3] + 2);
	}
	int ans = dp[n - 1];
	cout << ans << endl;
	return 0;
}
