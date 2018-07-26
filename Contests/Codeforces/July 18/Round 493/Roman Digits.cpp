#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int calc(int n) {
	set<int> dict;
	fori(L, 0, n + 1) {
		fori(X, 0, n - L + 1) {
			fori(V, 0, n - L - X + 1) {
				int I = n - L - X - V;
				int x = L * 50 + X * 10 + V * 5 + I * 1;
				dict.insert(x);
			}
		}
	}
	return dict.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	ll ans = 0;
	if (n < 13)
		ans = calc(n);
	else
		ans += calc(13) + (n - 13) * 49LL;
	cout << ans << endl;
	return 0;
}
