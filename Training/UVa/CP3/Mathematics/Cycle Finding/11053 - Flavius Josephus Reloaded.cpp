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

const int oo = 1e9;

ll n, a, b;

ll f(ll x) { return ((((a * x) % n) * x) % n + b) % n; }

ii cycleFinding(int xo) {
	ll tortoise = f(xo), hare = f(f(xo));
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
	int mu = 0; hare = xo;
	while (tortoise != hare) { hare = f(hare); mu++; }
	int lambda = 1; hare = f(tortoise);
	while (tortoise != hare) { hare = f(hare); lambda++; }
	return ii(mu, lambda);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n >> a >> b && n) {
		ii ans = cycleFinding(0);
		cout << n - ans.second << endl;
	}
	return 0;
}