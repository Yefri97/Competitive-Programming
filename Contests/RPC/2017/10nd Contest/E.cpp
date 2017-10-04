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

const int oo = 1e9, mxn = 600;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi v(mxn), A(mxn);
	fori(i, 0, mxn)
		v[i] = i * i;
	fori(b, 1, mxn) {
		fori(a, 1, b + 1) {
			int pos = lower_bound(v.begin(), v.end(), a * a + b * b) - v.begin();
			A[pos] += (v[pos] == a * a + b * b);
		}
	}
	fori(i, 1, mxn)
		A[i] += A[i - 1];
	int n;
	while (cin >> n && n)
		cout << A[n] << endl;
	return 0;
}