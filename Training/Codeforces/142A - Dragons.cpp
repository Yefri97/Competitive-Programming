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
	int s, n; cin >> s >> n;
	vector<ii> v(n);
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		v[i] = ii(a, b);
	}
	sort(v.begin(), v.end());
	bool ans = true;
	for (int i = 0; i < n; i++) {
		if (s > v[i].first) {
			s += v[i].second;
		} else {
			ans = false;
			break;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}