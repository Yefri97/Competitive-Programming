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
	int n; cin >> n;
	int mn = oo, ans = -1;
	fori(i, 0, n) {
		int ai; cin >> ai;
		int k = max(0, (ai - i + n - 1) / n);
		if (k < mn) {
			mn = k;
			ans = i;
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
