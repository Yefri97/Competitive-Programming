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
	int n, k; cin >> n >> k; k--;
	fori(i, 0, n)
		cin >> A[i];
	int val = A[k], pos = -1;
	fori(i, 0, n)
		if (A[i] != val)
			pos = i;
	if (pos > k) {
		cout << -1 << endl;
	} else {
		cout << pos + 1 << endl;
	}
	return 0;
}