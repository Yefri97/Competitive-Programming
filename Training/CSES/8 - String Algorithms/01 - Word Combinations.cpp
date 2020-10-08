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
typedef pair<long long, long long> ii;

const int oo = 1e9;
const int MN = 5010;
const int MD = 1e9 + 7;
const long long base = 1777771;
const long long mod1 = 999727999;
const long long mod2 = 1070777777;

vector<int> g[MN];
set<ii> dict[MN];

struct Hash {
	vector<ii> hs, pot;
	Hash(string s) {
		hs.resize(SZ(s) + 1); pot.resize(SZ(s) + 1);
		pot[0] = ii(1, 1);
		for (int i = 1; i <= SZ(s); i++) {
			hs[i].first = (hs[i - 1].first * base + s[i - 1]) % mod1;
			hs[i].second = (hs[i - 1].second * base + s[i - 1]) % mod2;
			pot[i].first = (pot[i - 1].first * base) % mod1;
			pot[i].second = (pot[i - 1].second * base) % mod2;
		}
	}
	ii get(int l, int r) { l++; r++;
		long long x1 = hs[r].first;
		long long y1 = (hs[l - 1].first * pot[r - l + 1].first) % mod1;
		long long x2 = hs[r].second;
		long long y2 = (hs[l - 1].second * pot[r - l + 1].second) % mod2;
		return ii((x1 - y1 + mod1) % mod1, (x2 - y2 + mod2) % mod2);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	string s; cin >> s;
	int m; cin >> m;
	while (m--) {
		string x; cin >> x;
		if (SZ(x) > SZ(s)) continue;
		Hash h(x);
		dict[SZ(x)].insert(h.get(0, SZ(x) - 1));
	}
	Hash h(s);
	fori(len, 1, SZ(s) + 1) if (SZ(dict[len]) > 0) {
		fori(i, 0, SZ(s)) {
			if (dict[len].count(h.get(i, i + len - 1)))
				g[i].push_back(i + len);
		}
	}
	vi dp(SZ(s) + 1); dp[SZ(s)] = 1;
	for (int i = SZ(s) - 1; i >= 0; i--) {
		for (int j : g[i])
			dp[i] = (dp[i] + dp[j]) % MD;
	}
	cout << dp[0] << endl;
	return 0;
}