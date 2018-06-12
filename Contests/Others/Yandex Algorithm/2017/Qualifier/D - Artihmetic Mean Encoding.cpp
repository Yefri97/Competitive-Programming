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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		int k = 1;
		while (__builtin_popcountll(k * n) > k) k++;
		priority_queue<int> pq;
		ll kn = k * n, it = 0;
		while (kn) {
			if (kn & 1) pq.push(it);
			kn >>= 1;
			it++;
		}
		while (k > pq.size()) {
			int u = pq.top(); pq.pop();
			pq.push(u - 1);
			pq.push(u - 1);
		}
		cout << k;
		while (!pq.empty()) {
			cout << " " << pq.top();
			pq.pop();
		}
		cout << endl;
	}
	return 0;
}