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

const int oo = 1e9, mxn = 200010;
ll A[mxn], B[mxn], C[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	// A
	fori(i, 0, n)
		cin >> A[i];
	// B
	ll sw = 0;
	fori(i, 0, k)
		sw += A[i];
	B[k - 1] = sw;
	fori(i, k, n) {
		sw += A[i];
		sw -= A[i - k];
		B[i] = sw;
	}
	// C
	C[n - 1] = n - 1;
	for (int i = n - 2; i >= k - 1; i--)
		C[i] = (B[i] >= B[C[i + 1]] ? i : C[i + 1]);
	// ans
	int a = 0, b = 0;
	ll max_val = -1;
	fori(i, k - 1, n - k) {
		ll val = B[i] + B[C[i + k]];
		if (val > max_val) {
			max_val = val;
			a = i;
			b = C[i + k];
		}
	} 
	cout << a - (k - 1) + 1 << " " << b - (k - 1) + 1 << endl;
	return 0;
}