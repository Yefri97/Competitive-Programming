#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

int p[MN], c[MN];

bool cmp(int i, int j) { return p[i] < p[j]; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	fori(i, 0, n)
		cin >> p[i];
	fori(i, 0, n)
		cin >> c[i];
	vi v(n);
	fori(i, 0, n) v[i] = i;
	sort(v.begin(), v.end(), cmp);
	vector<ll> ans(n);
	priority_queue<int> pq;
	ll sum = 0;
	fori(i, 0, n) {
		sum += c[v[i]];
		ans[v[i]] = sum;
		pq.push(-c[v[i]]);
		if (pq.size() > k) {
			int x = pq.top(); pq.pop();
			sum += x;
		}
	}
	fori(i, 0, n)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
