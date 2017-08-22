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

const int INF = 1e9, MOD = 1e9 + 7;
int A[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, y; cin >> x >> y;
	A[0] = x;
	A[1] = y;
	A[2] = y - x;
	A[3] = -x;
	A[4] = -y;
	A[5] = x - y;
	int n; cin >> n;
	cout << mod(A[(n - 1) % 6], MOD) << endl;
	return 0;
}