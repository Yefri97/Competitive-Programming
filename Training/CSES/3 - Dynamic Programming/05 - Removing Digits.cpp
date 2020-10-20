#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

vi digits(int x) {
	vi ans;
	while (x > 0) {
		ans.push_back(x % 10);
		x /= 10;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	vi dp(n + 1, oo);
	dp[0] = 0;
	fori(i, 1, n + 1) {
		for (int j : digits(i))
			dp[i] = min(dp[i], dp[i - j] + 1);
	}
	cout << dp[n] << endl;
	return 0;
}
