/*
 *  RPC 02st Contest 2017
 *  Problem I: Postman
 *  Outcome: Accepted | Category: Greedy
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll solver(priority_queue<ii> pq, int k) {
	ll target = 0;
	while (!pq.empty()) {
		ii tp = pq.top(); pq.pop();
		ll x = tp.first, m = tp.second;
		target += 2 * (m / k) * x;
		if (m % k) pq.push(ii(x, m % k));
		ll acc = 0, high = (pq.empty())? 0 : pq.top().first;
		while (acc < k) {
			if (pq.empty()) break;
			tp = pq.top(); pq.pop();
			x = tp.first; m = tp.second;
			if (acc + m < k) {
				acc += m;
			} else {
				pq.push(ii(x, m - (k - acc)));
				acc += k - acc;
			}
		}
		target += 2 * high;
	}
	return target;
}

int main() {
	priority_queue<ii> left, right;
	int n, k; cin >> n >> k;
	while (n--) {
		ll x, m; cin >> x >> m;
		if (x < 0) left.push(ii(-x, m));
		if (x > 0) right.push(ii(x, m));
	}
	ll ans = 0;
	ans += solver(left, k);
	ans += solver(right, k);
	cout << ans << endl;
	return 0;
}