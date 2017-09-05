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

const int oo = 1e9, mxn = 20010;

ll A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		fori(i, 0, n)
			cin >> A[i];
		sort(A, A + n);
		bool ans = false;
		fori(i, 0, n - 2)
			if (A[i] + A[i + 1] > A[i + 2])
				ans = true;
		cout << (ans ? "possible" : "impossible") << endl;
	}
	return 0;
}