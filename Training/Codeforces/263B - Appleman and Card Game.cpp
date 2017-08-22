#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vi freq(26);
	fori(i, 0, n){
		char c; cin >> c;
		freq[c - 'A']++;
	}
	sort(freq.rbegin(), freq.rend());
	ll ans = 0;
	for (int i = 0; k > 0; i++) {
		ll x = min(k, freq[i]);
		k -= x;
		ans += x * x;
	}
	cout << ans << endl;
	return 0;
}