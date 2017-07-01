#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 200010;
ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	sort(A, A + n);
	if (A[0] == A[n - 1]) {
		cout << 0 << " " << (n * (n - 1)) / 2 << endl;
	} else {
		ll a = 0, x = A[0];
		while (x == A[a]) a++;
		ll b = 0, y = A[n - 1];
		while (y == A[n - b - 1]) b++;
		cout << y - x << " " << a * b << endl;
	}
	return 0;
}