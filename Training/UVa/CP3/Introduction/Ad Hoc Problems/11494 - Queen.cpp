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
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2 && x1) {
		int ans;
		if (x1 == x2 && y1 == y2) ans = 0;
		else if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) ans = 1;
		else ans = 2;
		cout << ans << endl;
	}
	return 0;
}
