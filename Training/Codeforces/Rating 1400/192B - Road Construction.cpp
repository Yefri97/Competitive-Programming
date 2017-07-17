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
	int n, m; cin >> n >> m;
	vector<bool> vb(n, true);
	while (m--) {
		int a, b; cin >> a >> b; a--; b--;
		vb[a] = false;
		vb[b] = false;
	}
	int center = -1;
	fori(i, 0, n)
		if (vb[i]) center = i;
	cout << n - 1 << endl;
	fori(i, 0, n)
		if (i != center)
			cout << center + 1 << " " << i + 1 << endl;
	return 0;
}