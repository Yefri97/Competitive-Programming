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
const int MD = 1e9 + 7;

ll fastExp(ll b, ll e, ll m) {
	ll ans = 1;
	while (e > 0) {
		if (e & 1) ans = (ans * b) % m;
		b = (b * b) % m;
		e >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		cout << fastExp(a, fastExp(b, c, MD - 1), MD) << endl;
	}
	return 0;
}
