// Binary Search
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

const int INF = 1e9, MAXN = 100010;

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q, cs = 0;
	while (cin >> n >> q && (n || q)) {
		vector<int> A(n);
		fori(i, 0, n)
			cin >> A[i];
		sort(A.begin(), A.end());
		cout << "CASE# " << ++cs << ":" << endl;
		while (q--) {
			int x; cin >> x;
			int pos = lower_bound(A.begin(), A.end(), x) - A.begin();
			if (A[pos] == x)
				cout << x << " found at " << pos + 1 << endl;
			else
				cout << x << " not found" << endl;
		}
	}
	return 0;
}