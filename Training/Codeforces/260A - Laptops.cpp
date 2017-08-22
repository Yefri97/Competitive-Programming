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
	int n; cin >> n;
	vii v(n);
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		v[i] = ii(a, b);
	}
	sort(v.begin(), v.end());
	bool ans = false;
	fori(i, 1, n)
		ans |= (v[i - 1].second > v[i].second);
	cout << (ans ? "Happy Alex" : "Poor Alex") << endl;
	return 0;
}