#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 1010;
int cards[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	fori(i, 0, n) {
		int c; cin >> c; c--;
		cards[c] = 1;
	}
	int ans = 0, sw = 0;
	fori(i, 0, k)
		sw += cards[i];
	if (sw >= k - m) ans++;
	fori(i, k, 1000) {
		sw += cards[i];
		sw -= cards[i - k];
		if (sw >= k - m) ans++;
	}
	cout << ans << endl;
	return 0;
}