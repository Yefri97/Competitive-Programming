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

const int INF = 1e9, MAXN = 200000;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n)
		cin >> A[i];
	int acc = 0;
	fori(i, 0, k)
		acc += A[i];
	int min_val = acc, ans = 1;
	fori(i, k, n) {
		acc += A[i];
		acc -= A[i - k];
		if (acc < min_val) {
			acc = min_val;
			ans = i - k + 2;
		}
	}
	cout << ans << endl;
	return 0;
}