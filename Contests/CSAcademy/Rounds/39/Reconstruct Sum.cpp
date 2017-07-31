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

int A[2][10], B[20], C[20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, 10)
		fori(j, 0, 10)
			A[(i + j > 9)][(i + j) % 10]++;
	ll s; cin >> s;
	int n = log(s) / log(10);
	fori(i, 0, n) {
		cin >> B[i];
		C[i] = s % 10;
		s /= 10;
	}
	C[n] = s;
	ll ans = 1;
	fori(i, 0, n + 1)
		ans *= A[B[i]][C[i] - (i ? B[i-1] : 0)];
	cout << ans << endl;
	return 0;
}