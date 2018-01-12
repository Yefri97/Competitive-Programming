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
	int c, v0, v1, a, l; cin >> c >> v0 >> v1 >> a >> l;
	int curr = v0, ans = 1;
	while (curr < c) {
		curr += min(v1, v0 + a) - l;
		v0 += a;
		ans++;
	}
	cout << ans << endl;
	return 0;
}