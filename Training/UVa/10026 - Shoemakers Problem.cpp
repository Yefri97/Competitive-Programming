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
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 1010;

struct st {
	int t, f, id;
	st() {}
	st(int _t, int _f, int _id) : t(_t), f(_f), id(_id) {}
	bool operator < (st o) {
		if (o.f * t != f * o.t) return o.f * t < f * o.t;
		return id < o.id;
	}
};

st A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs; cin >> cs;
	while (cs--) {
		int n; cin >> n;
		fori(i, 0, n) {
			int a, b; cin >> a >> b;
			A[i] = st(a, b, i + 1);
		}
		sort(A, A + n);
		cout << A[0].id;
		fori(i, 1, n)
			cout << " " << A[i].id;
		cout << endl;
		if (cs) cout << endl;
	}
	return 0;
}