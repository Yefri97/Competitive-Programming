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

const int INF = 1e9, MAXN = 60;

struct st {
	int p, t;
	st() {}
	st(int _p, int _t) : p(_p), t(_t) {}
	bool operator < (st other) {
		if (p != other.p) return p > other.p;
		return t < other.t;
	}
} A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k; k--;
	fori(i, 0, n)
		cin >> A[i].p >> A[i].t;
	sort(A, A + n);
	int cnt = 0;
	fori(i, 0, n)
		cnt += (A[i].p == A[k].p && A[i].t == A[k].t);
	cout << cnt << endl;
	return 0;
}