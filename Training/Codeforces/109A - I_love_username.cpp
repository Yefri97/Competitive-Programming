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
	int n; cin >> n;
	int x; cin >> x;
	int max_val = x, min_val = x, amz = 0;
	fori(i, 0, n) {
		cin >> x;
		if (x > max_val)
			max_val = x, amz++;
		if (x < min_val)
			min_val = x, amz++;
	}
	cout << amz << endl;
	return 0;
}