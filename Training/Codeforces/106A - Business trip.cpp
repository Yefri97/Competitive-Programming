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

const int INF = 1e9, MAXN = 20;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k; cin >> k;
	fori(i, 0, 12)
		cin >> A[i];
	sort(A, A + 12);
	int ans = 0, acc = 0;
	while (ans < 12 && acc < k) {
		acc += A[11 - ans];
		ans++;
	}
	if (acc < k) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}