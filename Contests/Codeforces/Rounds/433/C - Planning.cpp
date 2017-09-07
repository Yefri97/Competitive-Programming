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

const int oo = 1e9, mxn = 300010;

ll A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n)
		cin >> A[i];
	priority_queue<ii> pq;
	fori(i, 0, min(n, k))
		pq.push(ii(A[i], i));
	ll acc = 0;
	vi ans(n);
	fori(i, 0, n) {
		ll t = i + k;
		if (t < n) pq.push(ii(A[t], t));
		int id = pq.top().second; pq.pop();
		acc += (t - id) * A[id];
		ans[id] = t;
	}
	cout << acc << endl;
	fori(i, 0, n)
		cout << ans[i] + 1 << " ";
	cout << endl;
	return 0;
}