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

	int n, x, k; cin >> n >> x >> k;
	vector<ll> v(n + 2);
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	stack<ll> s;
	vector<ll> out(n);
	ll sum = 0;
	
	v[0] = oo;
	v[n + 1] = oo;
	s.push(0);
	for (ll i = 1, val = 0; i <= n + 1; i++) {
		ll x = v[i];
		while (x > v[s.top()]) {
			ll p = s.top(); s.pop();
			val -= (p - s.top()) * v[p];
			out[p - 1] += (p - s.top()) * (i - p);
		}
		if (i == n + 1) continue;
		val += (i - s.top()) * v[i];
		s.push(i);
		sum += val;
	}

	v[0] = -oo;
	v[n + 1] = -oo;
	s.push(0);
	for (ll i = 1, val = 0; i <= n + 1; i++) {
		ll x = v[i];
		while (x < v[s.top()]) {
			ll p = s.top(); s.pop();
			val -= (p - s.top()) * v[p];
			out[p - 1] -= (p - s.top()) * (i - p);
		}
		if (i == n + 1) continue;
		val += (i - s.top()) * v[i];
		s.push(i);
		sum -= val;
	}

	sort(out.begin(), out.end());

	for (int i = 0; i < x; i++) {
		if (out[n - i - 1] < 0) break;
		sum += out[n - i - 1];
	}

	cout << sum << endl;

	return 0;
}