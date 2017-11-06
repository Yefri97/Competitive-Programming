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

const int oo = 1e9, MX = 250 * 250 + 10;

int A[MX], L[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n, p, q; cin >> n >> p >> q;
		vi mapper(n * n + 1, oo);
		fori(i, 0, p + 1) {
			int x; cin >> x;
			mapper[x] = i;
		}
		fori(i, 0, q + 1) {
			int x; cin >> x;
			A[i] = mapper[x];
		}
		int lis = 0;
		fori(i, 0, q + 1) {
			int pos = lower_bound(L, L + lis, A[i]) - L;
			L[pos] = A[i];
			lis = max(lis, pos + 1);
		}
		cout << "Case " << ++cs << ": " << lis << endl;
	}
	return 0;
}