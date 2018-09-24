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
	int tc; cin >> tc;
	fori(t, 0, tc) {
		cout << "Case #" << t + 1 << ":";
		int n, k; cin >> n >> k;
		ll v; cin >> v;
		vector<string> vs(n);
		fori(i, 0, n)
			cin >> vs[i];
		int x = (k * (v - 1)) % n;
		fori(i, 0, max(0, x + k - n))
			cout << " " << vs[i];
		fori(i, x, min(x + k, n))
			cout << " " << vs[i];
		cout << endl;
	}
	return 0;
}
