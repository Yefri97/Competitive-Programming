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

int f(int x) { return ((x * x) % 1000000) / 100; }

ii cycleFinding(int xo) {
	int tortoise = f(xo), hare = f(f(xo));
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
	int mu = 0; hare = xo;
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
	int lambda = 1; hare = f(tortoise);
	while (tortoise != hare) { hare = f(hare); lambda++; }
	return ii(mu, lambda);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x;
	while (cin >> x && x) {
		ii ans = cycleFinding(x);
		cout << ans.first + ans.second << endl;
	}
	return 0;
}