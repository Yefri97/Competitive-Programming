#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 100010;
ll temples[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll sum = 0;
		fori(i, 0, n) {
			ll x; cin >> x;
			sum += x;
			temples[i] = x;
		}
		temples[0] = 1;
		for (int i = 0; i < n; i++)
			temples[i] = min(temples[i], temples[i - 1] + 1);
		temples[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--)
			temples[i] = min(temples[i], temples[i + 1] + 1);
		ll h = 0;
		fori(i, 0, n)
			h = max(h, temples[i]);
		cout << sum - h * h << endl;
	}
	return 0;
}