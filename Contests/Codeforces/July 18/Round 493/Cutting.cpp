#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, b; cin >> n >> b;
	vi a(n), s(n);
	fori(i, 0, n) {
		cin >> a[i];
		s[i] = (a[i] % 2 ? 1 : -1);
	}
	fori(i, 1, n)
		s[i] += s[i - 1];
	priority_queue<int> pq;
	fori(i, 0, n - 1) if (s[i] == 0)
		pq.push(-abs(a[i + 1] - a[i]));
	int ans = 0;
	while (pq.size() > 0) {
		int x = pq.top(); pq.pop();
		if (b + x < 0) break;
		b += x;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
