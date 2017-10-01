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

const int oo = 1e9, mxn = 100010;

int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	while (cin >> n >> k) {
		fori(i, 0, n)
			cin >> A[i];
		int l = 0, r = 0, acc = 0;
		while (l < n) {
			while (r < n && A[r] + acc <= k) acc += A[r++];
			if (acc == k) break;
			acc -= A[l++];
		}
		if (l == n)
			cout << -1 << endl;
		else
			cout << l + 1 << " " << r << endl;
	}
	return 0;
}