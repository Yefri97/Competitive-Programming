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

const int oo = 1e9;

ll r;
ll A[5], B[5], C[5];

bool check(ll x) {
	ll sum = 0;
	fori(i, 0, 3)
		sum += max(0LL, A[i] * x - B[i]) * C[i];
	return sum <= r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	fori(i, 0, s.size())
		A[s[i] == 'B' ? 0 : s[i] == 'S' ? 1 : 2]++;
	cin >> B[0] >> B[1] >> B[2];
	cin >> C[0] >> C[1] >> C[2];
	cin >> r;
	if (check(0)) {
		ll low = 0, high = 1e13;
		while (high - low > 1) {
			ll mid = (high + low) * 0.5;
			if (check(mid))
				low = mid;
			else
				high = mid;
		}
		cout << low << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}