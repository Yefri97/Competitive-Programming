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

const int oo = 1e9, MX = 1e5 + 10, MD = 1e9 + 7;

int A[MX], last[MX];
int dp[MX], presum[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	map<int, int> dict;
	for (int l = 1, r = 1; r <= n; r++) {
		dict[A[r]]++;
		while (dict.size() > k) {
			dict[A[l]]--;
			if (dict[A[l]] == 0)
				dict.erase(A[l]);
			l++;
		}
		last[r] = l;
	}
	dp[0] = presum[0] = 1;
	for (int i = 1; i <= n; i++) {
		int r = i - 1, l = last[i] - 1;
		dp[i] = mod(presum[r] - (l == 0 ? 0 : presum[l - 1]), MD);
		presum[i] = mod(dp[i] + presum[i - 1], MD);
	}
	cout << dp[n] << endl;
	return 0;
}