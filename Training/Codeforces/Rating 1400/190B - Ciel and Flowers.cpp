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
	int r, g, b; cin >> r >> g >> b;
	int ans = r / 3 + g / 3 + b / 3;
	if (r >= 1 && g >= 1 && b >= 1) ans = max(ans, (r - 1) / 3 + (g - 1) / 3 + (b - 1) / 3 + 1);
	if (r >= 2 && g >= 2 && b >= 2) ans = max(ans, (r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3 + 2);
	cout << ans << endl;
	return 0;
}