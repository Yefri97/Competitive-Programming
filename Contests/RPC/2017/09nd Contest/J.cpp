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

const int oo = 1e9, mxn = 10010;

int hulam[mxn];

void gen(int n) {
	bitset<1000000> bs;
	bs.set(1); bs.set(2); bs.set(3);
	hulam[0] = 1; hulam[1] = 2;
	int x = 1;
	fori(i, 2, n) {
		while (bs.test(x)) x++;
		fori(j, 0, i) bs.set(hulam[j] + x);
		hulam[i] = x;
		bs.set(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	gen(mxn);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; n--;
		cout << hulam[n] << endl;
	}
	return 0;
}