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

const int INF = 1e9, MAXN = 110;
int A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		cin >> A[i];
	fori(i, 0, m)
		cin >> B[i];
	sort(A, A + n);
	sort(B, B + m);
	int t = max(2 * A[0], A[n - 1]);
	cout << (t < B[0] ? t : -1) << endl;
	return 0;
}