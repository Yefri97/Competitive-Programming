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
	int x, y;
	while (cin >> x >> y && x) {
		int n;
		if (x == y + 1) {
			n = y;
		} else {
			int low = 0, high = oo;
			while (high - low > 1) {
				int mid = (high + low) >> 1;
				if ((int)pow(mid, log(x) / log(mid + 1)) <= y)
					low = mid;
				else
					high = mid;
			}
			n = low;
		}
		int a = 1, b = x, m = 1;
		while (x != 1) {
			x /= (n + 1);
			m *= n;
			a += m;
			b += m * x;
		}
		cout << a - y << " " << b << endl;
	}
	return 0;
}