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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	vi v(4);
	while (t--) {
		cin >> v[0] >> v[1] >> v[2] >> v[3];
		sort(v.begin(), v.end());
		cout << (v[0] == v[1] && v[2] == v[3] ? "YES" : "NO") << endl;
	}
	return 0;
}