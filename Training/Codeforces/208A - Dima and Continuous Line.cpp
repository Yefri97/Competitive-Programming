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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	bool ans = false;
	fori(i, 0, n - 1) {
		fori(j, 0, i) {
			int x1 = min(A[i], A[i + 1]), x2 = max(A[i], A[i + 1]);
			int x3 = min(A[j], A[j + 1]), x4 = max(A[j], A[j + 1]);
			ans |= ((x3 < x1 && x1 < x4 && x4 < x2) || (x1 < x3 && x3 < x2 && x2 < x4));
		}
	}
	cout << (ans ? "yes" : "no") << endl;
	return 0;
}