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

const int oo = 1e9;

int solver(vi v, int b, int x) {
	int ans = 0, n = v.size();
	if (n == 1) return v[0] != x;
	if (b) {
		v[0] = 1 - v[0];
		v[1] = 1 - v[1];
		ans++;
	}
	for (int i = 0; i + 2 < n; i++) {
		if (v[i] != x) {
			v[i + 1] = 1 - v[i + 1];
			v[i + 2] = 1 - v[i + 2];
			ans++;
		}
	}
	if (v[n - 2] != x) {
		v[n - 1] = 1 - v[n - 1];
		ans++;
	}
	if (v[n - 1] != x)
		return oo;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n) {
		int x; cin >> x;
		v[i] = x % 2;
	}
	int ans1 = min(solver(v, 0, 1), solver(v, 1, 1));
	int ans2 = min(solver(v, 0, 0), solver(v, 1, 0));
	cout << (ans1 == oo ? -1 : ans1) << endl;
	cout << (ans2 == oo ? -1 : ans2) << endl;
	return 0;
}