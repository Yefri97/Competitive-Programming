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

const int oo = 1e9, MX = 100000;
ll A[MX], presum[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	sort(A, A + n);
	presum[0] = A[0];
	fori(i, 1, n)
		presum[i] = A[i] + presum[i - 1];
	ll sumdiff = 0;
	fori(i, 0, n)
		sumdiff += (i + 1) * A[i] - presum[i];
	ll acc = accumulate(A, A + n, 0LL);
	ll p = 2 * sumdiff + acc;
	ll q = n;
	cout << p / __gcd(p, q) << " " << q / __gcd(p, q) << endl;
	return 0;
}