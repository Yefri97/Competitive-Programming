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

const int oo = 1e9, mxn = 3e7;

int A[mxn+10], cnt[mxn+10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	fori(i, 0, m)
		cin >> A[i];
	fori(i, m, n)
		A[i] = (A[i - m] + A[i - m + 1]) % mxn;
	fori(i, 0, n)
		cnt[A[i]]++;
	int curr = 0;
	fori(i, 0, n) {
		while (cnt[curr] == 0) curr++;
		A[i] = curr;
		cnt[curr]--;
	}
	while (q--) {
		int id; cin >> id; id--;
		cout << A[id] << endl;
	}
	return 0;
}