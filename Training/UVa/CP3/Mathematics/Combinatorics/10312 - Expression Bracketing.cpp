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

const int oo = 1e9, mxn = 27;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<ll> c(mxn), sc(mxn);
	c[0] = 1, c[1] = 1;
	sc[0] = 0, sc[1] = 1;
	for (int i = 2; i < mxn; i++) {
		c[i] = (2 * (2 * i - 1) * c[i - 1]) / (i + 1); 
		sc[i] = (3 * (2 * i - 3) * sc[i - 1] - (i - 3) * sc[i - 2]) / i;
	}
	int n;
	while (cin >> n)
		cout << sc[n] - c[n - 1] << endl;
	return 0;
}