/*
 *  RPC 02st Contest 2017
 *  Problem H: Paint
 *  Outcome: Accepted | Category: Sweep line + DP
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> event;

map<ll, ll> best;

ll getUB(ll x) {
	map<ll, ll>::iterator it = best.upper_bound(x);
	return it->first;
}

int main() {
	priority_queue<event> sl;
	ll n, k; cin >> n >> k;
	while (k--) {
		ll a, b; cin >> a >> b;
		sl.push(event(a, b));
	}
	best[n + 1] = 0;
	while (!sl.empty()) {
		event tp = sl.top(); sl.pop();
		ll a = tp.first, b = tp.second;
		best[a] = max(best[getUB(b)] + (b - a + 1), best[getUB(a)]);
	}
	cout << n - best[getUB(0)] << endl;
	return 0;
}