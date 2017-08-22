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

const int oo = 1e9, mxn = 1010;

int A[mxn];

int countBits(int n, int x) {
	int cnt = 0;
	fori(i, 0, n) {
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	fori(i, 0, m)
		cin >> A[i];
	int me; cin >> me;
	int ans = 0;
	fori(i, 0, m)
		ans += (countBits(n, me ^ A[i]) <= k);
	cout << ans << endl;
	return 0;
}