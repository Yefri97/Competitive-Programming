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

const int oo = 1e9, mxn = 5010;
ii A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i].first >> A[i].second;
	sort(A, A + n);
	int curr = A[0].second;
	fori(i, 0, n - 1)
		curr = (A[i + 1].second >= curr ? A[i + 1].second : A[i + 1].first);
	cout << curr << endl;
	return 0;
}