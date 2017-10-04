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

const int oo = 1e9, MAXN = 10010;
int V[MAXN], C[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		cin >> V[i];
	fori(i, 0, m)
		cin >> C[i];
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	fori(i, 0, n)
		pq.push(ii(V[i] * C[i], i));
	fori(i, n, m) {
		ii front = pq.top(); pq.pop();
		front.first += V[front.second] * C[i];
		pq.push(front);
	}
	int ans;
	while (!pq.empty())
		ans = pq.top().first, pq.pop();
	cout << ans << endl;
	return 0;
}