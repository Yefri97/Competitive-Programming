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
	int n; cin >> n;
	int a = 0, b = 0, c = 0, d = 0;
	while (n--) {
		int l, r; cin >> l >> r;
		if (l) a++;
		else b++;
		if (r) c++;
		else d++;
	}
	cout << min(a, b) + min(c, d) << endl;
	return 0;
}