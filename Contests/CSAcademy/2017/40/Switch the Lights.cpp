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

int A[mxn], B[mxn], C[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	fori(i, 0, n) cin >> A[i];
	fori(i, 0, n) cin >> C[i];
	ll ans = 0;
	int cnt = 0;
	fori(i, 0, n) {
		cnt += B[i];
		if (cnt % 2) s[i] = (1 - (s[i] - '0')) + '0';
		if (s[i] == '1') {
			cnt++;
			B[A[i]]--;
			ans += C[i];
		}
	}
	cout << ans << endl;
	return 0;
}