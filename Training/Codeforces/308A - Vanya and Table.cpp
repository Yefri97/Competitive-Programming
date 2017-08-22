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
	int ans = 0;
	while (n--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		ans += (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	cout << ans << endl;
	return 0;
}