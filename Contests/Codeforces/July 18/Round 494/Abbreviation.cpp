#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 310;

int dp[MN][MN], len[MN];

int sum(int l, int r) {	return len[r] - (l > 0 ? len[l - 1] : 0); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<string> words(n);
	fori(i, 0, n)
		cin >> words[i];
	fori(i, 0, n)
		len[i] = words[i].size();
	fori(i, 1, n)
		len[i] += len[i - 1];
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			dp[j][i] = (words[i] == words[j] ? dp[j + 1][i + 1] + 1 : 0);
	int total = len[n - 1] + n - 1, ans = total;
	fori(i, 0, n) {
		fori(l, 1, n + 1) {
			int cnt = 1;
			fori(j, i + l, n) {
				if (dp[i][j] >= l) {
					j += l - 1;
					cnt++;
				}
			}
			if (cnt > 1)
				ans = min(ans, total - cnt * sum(i, i + l - 1) + cnt);
		}
	}
	cout << ans << endl;
	return 0;
}
