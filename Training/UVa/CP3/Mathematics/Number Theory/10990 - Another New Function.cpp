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

const int oo = 1e9, MX = 2000010;

bitset<MX> bs;
int phi[MX], depthphi[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	bs.set();
	fori(i, 0, MX) phi[i] = i;
	for (int i = 2; i < MX; i++) if (bs[i]) {
		for (int j = i; j < MX; j += i) {
			bs[j] = 0;
			phi[j] -= phi[j] / i;
		}
	}
	depthphi[1] = 0;
	for (int i = 2; i < MX; i++)
		depthphi[i] = depthphi[phi[i]] + 1;
	for (int i = 2; i < MX; i++)
		depthphi[i] += depthphi[i - 1];
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m >> n;
		cout << depthphi[n] - depthphi[m - 1] << endl;
	}
	return 0;
}