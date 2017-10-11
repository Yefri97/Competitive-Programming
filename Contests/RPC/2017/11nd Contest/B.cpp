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

const int oo = 1e9, mxn = 100010, kMod = 1e9 + 7;

int P[mxn], C[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> P[i];
	fori(i, 0, n)
		cin >> C[i];
	sort(P, P + n);
	sort(C, C + n);
	ll ans = 1;
	for (int itp = 0, itc = 0; itc < n; itc++) {
		while (itp < n && P[itp] <= C[itc]) itp++;
		ans = (ans * (itp - itc)) % kMod;
	}
	cout << ans << endl;
	return 0;
}