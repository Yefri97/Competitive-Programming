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

ll g(ll x) { return (x * (x + 1)) / 2; }

int A[] = {6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179};
int B[] = {8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	/*for (ll n = 2; n < 100000000; n++) {
		double x = sqrt(g(n));
		if (x == floor(x)) {
			cout << (int)x << " " << n << endl;
		}
	}*/
	fori(i, 0, 10)
		cout << setw(10) << A[i] << setw(10) << B[i] << endl;
	return 0;
}