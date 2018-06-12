#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	map<int, int> pos;
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x;
		pos[x] = i;
	}
	vi v;
	for (map<int, int>::iterator it = pos.begin(); it != pos.end(); it++)
		v.push_back(it->second);
	ll ans = 0;
	fori(i, 1, v.size())
		ans += min(mod(v[i] - v[i - 1], n), mod(v[i - 1] - v[i], n));
	cout << ans << endl;
	return 0;
}