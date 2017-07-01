// Bonus Feature: Base Number Conversion
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n >= 0) {
		stack<int> s;
		while (n) {
			s.push(n % 3);
			n /= 3;
		}
		if (s.empty()) s.push(0);
		while(!s.empty()) {
			int x = s.top(); s.pop();
			cout << x;
		}
		cout << endl;
	}
	return 0;
}