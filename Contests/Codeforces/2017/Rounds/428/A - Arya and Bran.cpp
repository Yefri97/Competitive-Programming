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
	int n, k; cin >> n >> k;
	int ans = -1, cnt = 0;
	fori(i, 0, n) {
		int x; cin >> x;
		cnt += x;
		int y = min(k, min(8, cnt));
		k -= y;
		cnt -= y;
		if (ans == -1 && k == 0) ans = i;
	}
	cout << ((ans == -1) ? -1 : ans + 1) << endl;
	return 0;
}