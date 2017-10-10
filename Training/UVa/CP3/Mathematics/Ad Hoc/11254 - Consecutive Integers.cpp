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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n != -1) {
		int b = n, a = n;
		for (int i = sqrt(2 * n); i > 0; i--) {
			int p = 2 * n - i * i + i, q = 2 * i;
			if (p % q == 0) {
				a = p / q;
				b = a + i - 1;
				break;
			}
		}
		cout << n << " = " << a << " + ... + " << b << endl;
	}
	return 0;
}