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

const int oo = 1e9, mxn = 100010;
int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	fori(i, 1, s.size())
		A[i] = (s[i] == s[i - 1]) + A[i - 1];
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		cout << A[r] - A[l] << endl;
	}
	return 0;
}